#include <linux/module.h>

static int __init chardevbase_init(void)
{
        printk("chardevbase init!\n");
        return 0;
}

static void __exit chardevbase_exit(void)
{
        printk("chardevbase exit!\n");
}


module_init(chardevbase_init); /* 入口 */
module_exit(chardevbase_exit); /* 出口 */

MODULE_LICENSE("GPL");
MODULE_AUTHOR("wanglei");
