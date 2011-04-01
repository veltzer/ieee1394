#include <linux/cdev.h>
int cdev_index(struct inode *inode)
{
       int idx;
       struct kobject *kobj;

       kobj = kobj_lookup(cdev_map, inode->i_rdev, &idx);
       if (!kobj)
               return -1;
       kobject_put(kobj);
       return idx;
}
