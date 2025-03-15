
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Get exponent of a floating-point value
 *
 * @param x the floating-point value to get the exponent of
 * @return the exponent of the floating-point value
 */
double logb(double x) {
	return __builtin_logb(x);
}

#endif
