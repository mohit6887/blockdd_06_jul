#include "headers.h"
#include "declerations.h"

int init_tag_set(struct blk_mq_set *set, void *data)
{
	printk(KERN_INFO"%s: Begin \n",__func__);
	set->ops=&mq_ops;
}
