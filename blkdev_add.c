#include"headers.h"
#include"declerations.h"

struct blkdev* blkdev_add(int major,int minor,char* name,sector_t capacity)
{

	int ret;
	struct blkdev* ldev;
	printk(KERN_INFO"%s begin  :\n",__func__);
	pr_info("Add device %s capacity %ld sectors \n",name ,(long int)capacity);
	ldev=kzalloc(sizeof(struct blkdev),GFP_KERNEL);
	if(!ldev)
	{
		pr_err("%s %d :Error fAILURE",__func__,__LINE__);
		ret=-ENOMEM;
		goto FAIL;
	}
	INIT_LIST_HEAD(&ldev->link);

	ldev->capacity=capacity;
	ldev->data=__vmalloc(capacity << SECTOR_SHIFT,GFP_NOIO|__GFP_ZERO);
	if(!ldev->data)
	{
		ret=-ENOMEM;
		kfree(ldev);
		goto FAIL;
	}
#ifdef REQUEST_BASED
	ret=init_tag_set_(&ldev->tag_set,ldev);
	if(ret)
	{
		pr_err(" Failed ot allocate memory for the tag set \n");
		vfree(ldev->data);
		goto FAIL;
	}
#endif
	printk(KERN_INFO"%s After vmalloc End :\n",__func__);
	return 0;
FAIL:
	pr_err("%s: %d:Error kzalloc failure \n",__func__,__LINE__);
	return 0;

}
