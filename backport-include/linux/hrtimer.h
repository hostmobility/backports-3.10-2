#ifndef __BACKPORT_LINUX_HRTIMER_H
#define __BACKPORT_LINUX_HRTIMER_H
#include_next <linux/hrtimer.h>

#if LINUX_VERSION_IS_LESS(3,17,0)
u64 bp_ktime_divns(const ktime_t kt, s64 div);
#define ktime_divns bp_ktime_divns
#endif /* < 3.17 */

#endif /* __BACKPORT_LINUX_HRTIMER_H */
