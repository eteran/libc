
#define _ELIBC_SOURCE
#include <time.h>

#ifdef _HAS_FPU

/**
 * @brief Calculate the difference between two time values
 *
 * @param time1 The first time value
 * @param time0 The second time value
 * @return The difference between the two time values in seconds
 */
double difftime(time_t time1, time_t time0) {
	return (double)(time1 - time0);
}

#endif
