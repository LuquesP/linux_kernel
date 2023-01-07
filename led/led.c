#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/gpio.h>
#include <linux/delay.h>



// resource for device file  
// https://sysplay.github.io/books/LinuxDrivers/book/Content/Part05.html

#define ROW_1_GPIO 1
#define ROW_2_GPIO 2
#define ROW_3_GPIO 3
#define ROW_4_GPIO 4
#define ROW_5_GPIO 12
#define ROW_6_GPIO 11
#define ROW_7_GPIO 10
#define ROW_8_GPIO 9

#define COL_1_GPIO 5
#define COL_2_GPIO 6
#define COL_3_GPIO 7
#define COL_4_GPIO 8
#define COL_5_GPIO 16
#define COL_6_GPIO 15
#define COL_7_GPIO 14
#define COL_8_GPIO 13

static int __init led_matrix_init(void)
{

  int i;
  int cnt = 0; 

  printk(KERN_INFO "Hello, world!\n");
  // Set all row and column GPIOs as outputs
 // Set all row and column GPIOs as outputs
  for (i = ROW_1_GPIO; i <= ROW_8_GPIO; i++)
    gpio_direction_output(i, 0);
  for (i = COL_1_GPIO; i <= COL_8_GPIO; i++)
    gpio_direction_output(i, 0);

  // Turn on all LEDs
  while (1)
  {
    for (i = ROW_1_GPIO; i <= ROW_8_GPIO; i++)
      gpio_set_value(i, 1);
    for (i = COL_1_GPIO; i <= COL_8_GPIO; i++)
      gpio_set_value(i, 1);
    msleep(500);  // Sleep for 500 milliseconds
    for (i = ROW_1_GPIO; i <= ROW_8_GPIO; i++)
      gpio_set_value(i, 0);
    for (i = COL_1_GPIO; i <= COL_8_GPIO; i++)
      gpio_set_value(i, 0);
    msleep(500);  // Sleep for 500 milliseconds
    cnt = cnt + 1; 
    if (cnt == 5) {
      break; 
    }
  }

  return 0;
}

static void __exit led_matrix_exit(void)
{

  // Turn off all LEDs before exiting
  int i;

  for (i = ROW_1_GPIO; i <= ROW_8_GPIO; i++)
    gpio_set_value(i, 1);
  for (i = COL_1_GPIO; i <= COL_8_GPIO; i++)
    gpio_set_value(i, 1);

  printk(KERN_INFO "Goodbye, world!\n");
}

module_init(led_matrix_init);
module_exit(led_matrix_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A kernel module to control an 8"); 