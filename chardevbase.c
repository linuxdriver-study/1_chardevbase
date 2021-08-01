#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>

#define CHRDEVBASE_MAJOR        200
#define CHRDEVBASE_NAME         "chrdevbase"

static int chrdevbase_open(struct inode *inode, struct file *filp);
static int chrdevbase_release(struct inode *inode, struct file *filp);
static ssize_t chrdevbase_read(struct file *filp,
                               char __user *buf,
                               size_t cnt,
                               loff_t *offt);
static ssize_t chrdevbase_write(struct file *filp,
                                const char __user *buf,
                                size_t cnt,
                                loff_t *offt);

/*
 * @brief 字符设备操作集合
 */
static struct file_operations chrdevbase_fops = {
        .owner = THIS_MODULE,
        .open = chrdevbase_open,
        .release = chrdevbase_release,
        .read = chrdevbase_read,
        .write = chrdevbase_write,
};


static int chrdevbase_open(struct inode *inode, struct file *filp)
{
        printk("chrdevbase open!\n");
        return 0;
}

static int chrdevbase_release(struct inode *inode, struct file *filp)
{
        printk("chrdevbase release!\n");
        return 0;
}

static ssize_t chrdevbase_read(struct file *filep,
                               char __user *buf, 
                               size_t cnt,
                               loff_t *offt)
{
        printk("chrdevbase read!\n");
        return 0;
}
static ssize_t chrdevbase_write(struct file *filp,
                                const char __user *buf,
                                size_t cnt, 
                                loff_t *offt)
{
        printk("chrdevbase write!\n");
        return 0;
}

static int __init chardevbase_init(void)
{
        int ret = 0;
        ret = register_chrdev(CHRDEVBASE_MAJOR, CHRDEVBASE_NAME, &chrdevbase_fops);
        if(ret < 0) {
                printk("register chardev error!\n");
        }

        printk("chardevbase init!\n");
        return 0;
}

static void __exit chardevbase_exit(void)
{
        unregister_chrdev(CHRDEVBASE_MAJOR, CHRDEVBASE_NAME);
        printk("chardevbase exit!\n");
}


module_init(chardevbase_init); /* 入口 */
module_exit(chardevbase_exit); /* 出口 */

MODULE_LICENSE("GPL");
MODULE_AUTHOR("wanglei");
