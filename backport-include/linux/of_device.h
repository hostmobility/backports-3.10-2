#ifndef __BP_OF_DEVICE_H
#define __BP_OF_DEVICE_H
#include_next <linux/of_device.h>
#include <linux/version.h>

#if LINUX_VERSION_IS_LESS(4,18,0)
static inline int backport_of_dma_configure(struct device *dev,
					    struct device_node *np,
					    bool force_dma)
{
#if LINUX_VERSION_IS_GEQ(4,15,0)
	dev->bus->force_dma = force_dma;
	return of_dma_configure(dev, np);
#elif LINUX_VERSION_IS_GEQ(4,12,0)
	return of_dma_configure(dev, np);
#elif LINUX_VERSION_IS_GEQ(4,1,0)
	of_dma_configure(dev, np);
	return 0;
#else
	return 0;
#endif
}
#define of_dma_configure LINUX_BACKPORT(of_dma_configure)
#endif /* < 4.18 */

#if LINUX_VERSION_IS_LESS(4,12,0)
#if LINUX_VERSION_IS_GEQ(4,4,0)
ssize_t bp_of_device_modalias(struct device *dev, char *str, ssize_t len);
#define of_device_modalias bp_of_device_modalias
#endif /* > 4.4.0 */
#endif /* < 4.12 */

#endif /* __BP_OF_DEVICE_H */
