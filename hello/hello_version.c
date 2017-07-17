#include <linux/init.h>
#include <linux/module.h>
#include <linux/i2c.h>
#include <linux/utsname.h>
#include <linux/time.h>

static char *who_param = NULL;
module_param(who_param, charp, 0644);

#define MAX_WHO_SIZE 25
static char who_param_buf[MAX_WHO_SIZE];
module_param_string(who_param2, who_param_buf, MAX_WHO_SIZE, 0644);

struct timeval load_time, unload_time;

static int __init hello_init(void)
{
	do_gettimeofday(&load_time);

	if (who_param) {
		printk(KERN_ALERT "Hello %s. You are currently using Linux %s\n", who_param, utsname()->version);
	} else {
		printk(KERN_ALERT "Hello. You are currently using Linux %s\n", utsname()->version);
	}

	if (strlen(who_param_buf)> 0){
		printk(KERN_ALERT "Also you specified %s\n", who_param_buf);
	}
	return 0;
}

static void __exit hello_exit(void)
{
	struct timeval diff_time;
	do_gettimeofday(&unload_time);

	diff_time.tv_sec = unload_time.tv_sec - load_time.tv_sec;
	diff_time.tv_usec = unload_time.tv_usec - load_time.tv_usec;
	if (diff_time.tv_usec < 0) {
	  diff_time.tv_usec += 1000000;
	  diff_time.tv_sec -= 1;
	}
	 
	printk(KERN_ALERT "Driver loaded for %ld seconds, %ld usec\n", diff_time.tv_sec, diff_time.tv_usec);
	printk(KERN_ALERT "Goodbye\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("JehTech");
MODULE_DESCRIPTION("An example");
