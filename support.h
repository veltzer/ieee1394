#ifndef __support_h
#define __support_h

#include <linux/kobject.h>
#include <linux/kdev_t.h>
#include <linux/list.h>

int cdev_index(struct inode *inode);

#endif // __support_h
