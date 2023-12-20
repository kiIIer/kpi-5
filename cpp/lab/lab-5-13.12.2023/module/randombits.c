#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/random.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "randombits"
#define BUF_LEN 80
MODULE_LICENSE("GPL");


static int major;
static char msg[BUF_LEN];

static ssize_t device_read(struct file *filp, char __user *buffer, size_t length, loff_t *offset) {
    int bytes_read = 0;
    if (*offset >= BUF_LEN)
        return 0;

    while (length && *offset < BUF_LEN) {
        put_user(msg[*offset], buffer++);
        length--;
        (*offset)++;
        bytes_read++;
    }
    return bytes_read;
}

static int device_open(struct inode *inode, struct file *file) {
    static int counter = 0;
    sprintf(msg, "Random bits #%d\n", counter++);
    get_random_bytes(msg, sizeof(msg));
    return 0;
}

static struct file_operations fops = {
    .read = device_read,
    .open = device_open,
};

static int __init randombits_init(void) {
    major = register_chrdev(0, DEVICE_NAME, &fops);
    if (major < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", major);
        return major;
    }
    printk(KERN_INFO "I was assigned major number %d. To talk to\n", major);
    printk(KERN_INFO "the driver, create a dev file with\n");
    printk(KERN_INFO "'mknod /dev/%s c %d 0'.\n", DEVICE_NAME, major);
    printk(KERN_INFO "Try various minor numbers. Try to cat and echo to\n");
    printk(KERN_INFO "the device file.\n");
    printk(KERN_INFO "Remove the device file and module when done.\n");
    return 0;
}

static void __exit randombits_exit(void) {
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO "Goodbye, world!\n");
}

module_init(randombits_init);
module_exit(randombits_exit);

