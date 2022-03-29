/*************************************************************************
	> File Name: myvivi.c
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: 2022年03月28日 星期一 17时30分05秒
 ************************************************************************/
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/errno.h>
#include <linux/fs.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/mm.h>
#include <linux/ioport.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/pci.h>
#include <linux/random.h>
#include <linux/version.h>
#include <linux/mutex.h>
#include <linux/videodev2.h>
#include <linux/dma-mapping.h>
#include <linux/interrupt.h>
#include <linux/kethread.h>
#include <linux/highmen.h>
#include <linux/freezer.h>
#include <media/videobuf-vmalloc.h>
#include <media/v4l2-device.h>
#include <media/v4l2-ioctl.h>

static int myvivi_init(void)
{
	return 0;
}

static void myvivi_exit(void)
{

}

module_init(myvivi_init)
{

}

module_exit(myvivi_exit)
{

}

MODULE_LINCENSE("Dual BSD/GPL");



