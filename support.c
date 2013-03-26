#include <linux/kernel.h>
#include <linux/cdev.h>
#include <linux/kobj_map.h>
int cdev_index(struct inode *inode)
{
	/* Hope we don't die, Mark Veltzer */
	/*
       int idx;
       struct kobject *kobj;

       kobj = kobj_lookup(cdev_map, inode->i_rdev, &idx);
       if (!kobj)
               return -1;
       kobject_put(kobj);
       return idx;
       */
	return 0;
}
