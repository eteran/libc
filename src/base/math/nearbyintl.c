
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Round a floating-point value to the nearest integer value according to the current rounding mode
 *
 * @param x the floating-point value to round
 * @return the rounded value
 */
long double nearbyintl(long double x) {
	return __builtin_nearbyintl(x);
}

#endif
