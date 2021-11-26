// SPDX-License-Identifier: GPL-2.0
/* h_param.c */
#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("GPL");
static char *whom = "MAI";
module_param(whom, charp, 0644);
MODULE_PARM_DESC(whom, "Recipient of the hello message");
static char *whom1 = "Lecturer";
module_param(whom1, charp, 0644);
MODULE_PARM_DESC(whom1, "Another recipient of the hello message");
static int howmany = 2;
module_param(howmany, int, 0644);
MODULE_PARM_DESC(howmany, "Number of greetings");

static int __init hello_init(void)
{
	int i;
	for (i = 0; i < howmany; i++)
		if (i==0)
			pr_alert("(%d) Hello, %s\n", i, whom);
		else
			pr_alert("(%d) Hello, %s\n", i, whom1);				
	return 0;
}
static void __exit hello_exit(void)
{
	pr_alert("Goodbye, dears %s and %s\n", whom, whom1);
}
module_init(hello_init);
module_exit(hello_exit);
