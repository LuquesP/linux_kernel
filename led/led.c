#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/init.h>
#include <linux/gpio.h>
#include <linux/delay.h>
#include <linux/uaccess.h>
#include <linux/string.h>
#include <linux/ktime.h>  


// resource for device file  
// https://sysplay.github.io/books/LinuxDrivers/book/Content/Part05.html
// timer im kernel 
// https://stackoverflow.com/questions/16032228/how-to-run-while-loop-for-some-millisecond-in-linux-kernel

static dev_t first; // Global variable for the first device number
static struct cdev c_dev; // Global variable for the character device structure
static struct class *cl; // Global variable for the device class

#define DRIVER_NAME "led" 

unsigned int gpio_rows[] = {
        5, 
        6, 
        7, 
        8, 
        16, 
        15, 
        14, 
        13, 

}; 

unsigned int gpio_cols[] = {
        1, 
        2, 
        3, 
        4, 
        12, 
        11,
        10, 
        9, 
}; 

static char command_buffer[255]; 
static char buffer_pointer = 0; 

int up_matrix[8][8] = {
    {0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0},
    {1, 0, 0, 1, 1, 0, 0, 1},
    {0, 1, 0, 1, 1, 0, 1, 0},
    {0, 0, 1, 0, 0, 1, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0},
};

int down_matrix[8][8] = {
    {0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 0, 0},
    {0, 1, 0, 1, 1, 0, 1, 0},
    {1, 0, 0, 1, 1, 0, 0, 1},
    {0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0},
};

void draw_arrow(void){
    int matrix[8][8] = {0};
    // memcpy(matrix, clear_matrix, sizeof(matrix));  
    int row, col;
    unsigned long j0, j1, delay; 
    int seconds = 10;   
    int len_command_buffer = (int)strlen(command_buffer) - 1; 
    printk("command_buffer: %.*s\n", len_command_buffer, command_buffer); 
    if (strncmp(command_buffer, "down", len_command_buffer) == 0) {
        printk("command is down \n"); 
        memcpy(matrix, down_matrix, sizeof(matrix)); 
    }
    if(strncmp(command_buffer, "up", len_command_buffer) == 0){
        printk("command is up\n"); 
        memcpy(matrix, up_matrix, sizeof(matrix)); 
    }
    delay = msecs_to_jiffies(seconds * 1000 ); 
    j0 = jiffies; 
    j1 = j0 + delay;
    while (time_before(jiffies, j1)) {
        for (row = 0; row < 8; row++) {
            gpio_set_value(gpio_rows[row], 1);
            for (col = 0; col < 8; col++) {
                if (matrix[row][col] == 1) {
                    gpio_set_value(gpio_cols[col], 0);
                } else {
                    gpio_set_value(gpio_cols[col], 1);
                }
            }
            gpio_set_value(gpio_rows[row], 0);
        }
    }
}
static ssize_t my_write(struct file *f, const char *user_buffer, size_t count,
    loff_t *off)
{
    int to_copy, not_copied, delta; 

    printk(KERN_INFO "Driver: write()\n");

    to_copy = min(count, sizeof(command_buffer)); 

    not_copied = copy_from_user(command_buffer, user_buffer, to_copy); 
    buffer_pointer = to_copy;

    delta = to_copy - not_copied; 

    draw_arrow();


    return delta; 

}

static ssize_t my_read(struct file *f, char *user_buffer, size_t count, loff_t *off)
{
    int to_copy, not_copied, delta; 
    
    printk(KERN_INFO "Driver: read()\n");

    to_copy = min(count, buffer_pointer ); 

    not_copied = copy_to_user(user_buffer, command_buffer, to_copy); 

    delta = to_copy - not_copied;

    return delta;  


}
static int my_open(struct inode *i, struct file *f)
{
    printk(KERN_INFO "Driver: open()\n");
    return 0;
}
static int my_close(struct inode *i, struct file *f)
{
    printk(KERN_INFO "Driver: close()\n");
    return 0;
}
static struct file_operations pugs_fops =
{
    .owner = THIS_MODULE,
    .open = my_open,
    .release = my_close,
    .read = my_read,
    .write = my_write
};


static int __init led_matrix_init(void)
{
    int ret;
    int i; 
    struct device *dev_ret;

    printk(KERN_INFO "LED INIT");

    // Device nummer festelegen
    if ((ret = alloc_chrdev_region(&first, 0, 1, "LED")) < 0)
    {
        printk("device konnte nicht registriert werden\n"); 
        return ret;
    }
    printk("Device Nr. Major:%d, Minor %d wurde registriert\n", first >> 20, first && first && 0xfffff); 

    // Device Klasse erstellen 
    if (IS_ERR(cl = class_create(THIS_MODULE, "chardrv")))
    {   
        printk("Device class konnte nicht erstellt werden\n"); 
        unregister_chrdev_region(first, 1);
        return PTR_ERR(cl);
    }

    // Device File erstellen 
    if (IS_ERR(dev_ret = device_create(cl, NULL, first, NULL, DRIVER_NAME)))
    {
        printk("device file konnte nicht erstellt werden\n"); 
        class_destroy(cl);
        unregister_chrdev_region(first, 1);
        return PTR_ERR(dev_ret);
    }
    // Device File initialisieren 
    cdev_init(&c_dev, &pugs_fops);

    // Regestrierung Device zum Kernel
    if ((ret = cdev_add(&c_dev, first, 1)) < 0)
    {
        device_destroy(cl, first);
        class_destroy(cl);
        unregister_chrdev_region(first, 1);
        return ret;
    }

    //init gpios   
    for(i = 0; i < 8; i++) {
        if (gpio_request(gpio_rows[i], NULL)){
            printk("led_driver - Error Init rows GPIO %d\n", gpio_rows[i]);  
        }
        if (gpio_request(gpio_cols[i], NULL)){
            printk("led_driver - Error Init cols GPIO %d\n", gpio_cols[i]); 
        }

    //setzen der output richtung
    for(i = 0; i < 8; i++){
        if (gpio_direction_output(gpio_rows[i], 0)){
            printk("led_driver Error setzen der row GPIO %d als output\n", i); 
        }
        if(gpio_direction_output(gpio_cols[i], 0)){
            printk("led_driver Error setzen der row GPIO %d als output\n", i); 
        }
    }
    
    }

  return 0;
}

static void __exit led_matrix_exit(void)
{
    int i; 
    for (i=0; i<8; i++){
        gpio_set_value(gpio_rows[i], 0);  
        gpio_set_value(gpio_cols[i], 0); 
        gpio_free(gpio_rows[i]); 
        gpio_free(gpio_cols[i]); 
    }
  // Turn off all LEDs before exiting
  cdev_del(&c_dev);
  device_destroy(cl, first);
  class_destroy(cl);
  unregister_chrdev_region(first, 1);
  printk(KERN_INFO "Goodbye, Kernel!\n");
}

module_init(led_matrix_init);
module_exit(led_matrix_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A kernel module to control an 8"); 