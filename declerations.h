MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Memory Allocation");
#ifndef MAJORNO 
#define MAJORNO 0
#endif

#ifndef MINORNO
#define MINORNO 0
#endif


#ifndef BDDNAME
#define BDDNAME "BDD6.x"
#endif
int init_tag_set(struct blk_mq_tag_set*,void*);
//static blk_status_t
static struct blk_mq_ops mq_ops=
{
	.queue_rq=_queue_rq,   // for user defined operation on queue
};


//extern char *blkdev_catalog;
struct blkdev
{
	struct list_head link;
	sector_t capacity; /*Device size in sectors */
	u8 *data;
//#ifdef CONFIG_SBLKDEV_REQUESTS_BASED
#ifdef REQUESTS_BASED
	struct blkl_mq_tag_set tag_set;
#endif
//	struct gendisk *disk;
};

extern int majorno;
extern int minorno;

extern struct blkdev *dev;
struct blkdev *blkdev_add(int,int,char*,sector_t);
