#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/slab.h>
#include <linux/limits.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mike Molchanov");
MODULE_DESCRIPTION("An advanced Linux colonel module to complete tasks 1-7");
MODULE_VERSION("0.2");

struct my_list
{
    int data;
    struct list_head list;
};

static LIST_HEAD(my_list_head);

static int __init advanced_kernel_init(void)
{
    struct my_list *new_node;
    struct my_list *cursor;
    int test_data[] = {12, 16, 26, 9, 12, 12, 10};
    int i;
    int conjunction, largest, smallest, M;

    printk(KERN_INFO "Advanced Kernel Module Initialized\n");

    for (i = 0; i < 7; ++i)
    {
        new_node = kmalloc(sizeof(*new_node), GFP_KERNEL);
        new_node->data = test_data[i];
        list_add_tail(&new_node->list, &my_list_head);
    }

    // Task 4.1: Conjunction of All List Elements
    conjunction = 0xFF;
    list_for_each_entry(cursor, &my_list_head, list)
    {
        conjunction &= cursor->data;
    }
    printk(KERN_INFO "Conjunction of all elements: %d\n", conjunction);

    // Task 4.2: Find the Largest Value in the List
    largest = INT_MIN;
    list_for_each_entry(cursor, &my_list_head, list)
    {
        if (cursor->data > largest)
        {
            largest = cursor->data;
        }
    }
    printk(KERN_INFO "Largest value in the list: %d\n", largest);

    // Task 4.3: Find the Smallest Value in the List
    smallest = INT_MAX;
    list_for_each_entry(cursor, &my_list_head, list)
    {
        if (cursor->data < smallest)
        {
            smallest = cursor->data;
        }
    }
    printk(KERN_INFO "Smallest value in the list: %d\n", smallest);

    // Task 4.4: Divide List Elements by M
    M = 25;
    list_for_each_entry(cursor, &my_list_head, list)
    {
        cursor->data /= M;
        printk(KERN_INFO "Element divided by %d: %d\n", M, cursor->data);
    }

    // Task 4.5: Shift List Elements Left by 1 Bit
    list_for_each_entry(cursor, &my_list_head, list)
    {
        cursor->data <<= 1;
        printk(KERN_INFO "Element shifted left: %d\n", cursor->data);
    }

    // Task 4.6: Shift List Elements Right by 1 Bit
    list_for_each_entry(cursor, &my_list_head, list)
    {
        cursor->data >>= 1;
        printk(KERN_INFO "Element shifted right: %d\n", cursor->data);
    }

    // Task 4.7: Invert List Elements
    list_for_each_entry(cursor, &my_list_head, list)
    {
        cursor->data = ~cursor->data;
        printk(KERN_INFO "Element inverted: %d\n", cursor->data);
    }

    return 0;
}

static void __exit advanced_kernel_exit(void)
{
    struct my_list *cursor, *tmp;

    list_for_each_entry_safe(cursor, tmp, &my_list_head, list)
    {
        list_del(&cursor->list);
        kfree(cursor);
    }

    printk(KERN_INFO "Advanced Kernel Module Exited\n");
}

module_init(advanced_kernel_init);
module_exit(advanced_kernel_exit);
