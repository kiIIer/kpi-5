#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mike Molchanov");
MODULE_DESCRIPTION("A simple hello world kernel module");
MODULE_VERSION("0.1");

static int __init hello_kernel_init(void) {
   printk(KERN_INFO "Hello, Kernel!\n");
   return 0;
}

static void __exit hello_kernel_exit(void) {
   printk(KERN_INFO "Goodbye, Kernel!\n");
}

module_init(hello_kernel_init);
module_exit(hello_kernel_exit);

