#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x90f75b7e, "module_layout" },
	{ 0xcce0699e, "cdev_del" },
	{ 0xfe990052, "gpio_free" },
	{ 0xc29f9195, "gpiod_direction_output_raw" },
	{ 0x47229b5c, "gpio_request" },
	{ 0x9ab547c5, "class_destroy" },
	{ 0x97877479, "device_destroy" },
	{ 0x1d01e681, "cdev_add" },
	{ 0xf37beb9b, "cdev_init" },
	{ 0x42d9689d, "device_create" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0xcfffe6ec, "__class_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0x5f754e5a, "memset" },
	{ 0xae353d77, "arm_copy_from_user" },
	{ 0x8f678b07, "__stack_chk_guard" },
	{ 0x3ea1b6e4, "__stack_chk_fail" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x9d669763, "memcpy" },
	{ 0x84b183ae, "strncmp" },
	{ 0x97255bdf, "strlen" },
	{ 0x51a910c0, "arm_copy_to_user" },
	{ 0xf08551e, "gpiod_set_raw_value" },
	{ 0x6d44e361, "gpio_to_desc" },
	{ 0x92997ed8, "_printk" },
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "B44D84DC4E4001F4C9AE441");
