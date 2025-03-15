
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Round the floating point argument x to an integer value in floating point format,
 * using the current rounding mode.
 *
 * @param x the floating point value to round
 * @return the rounded value
 */
long double nearbyintl(long double x) {
	return __builtin_nearbyintl(x);
}

#endif
