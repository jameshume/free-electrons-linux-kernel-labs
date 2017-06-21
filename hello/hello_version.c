#include <linux/init.h>
#include <linux/module.h>
#include <linux/i2c.h>
#include <linux/utsname.h>

/* Add your code here */
static int hello_init(void)
{
	printk(KERN_ALERT "Hello. You are currently using Linux %s\n", utsname()->version);
	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "Goodbye\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("JehTech");
MODULE_DESCRIPTION("An example");
