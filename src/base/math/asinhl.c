
#define _ELIBC_SOURCE
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the hyperbolic arc sine of a floating point number
 *
 * @param x the floating point number to compute the hyperbolic arc sine of
 * @return the hyperbolic arc sine of the floating point number
 */
long double asinhl(long double x) {
	return __builtin_asinhl(x);
}

#endif
