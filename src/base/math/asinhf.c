
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the hyperbolic arc sine of a floating point number
 *
 * @param x the floating point number to compute the hyperbolic arc sine of
 * @return the hyperbolic arc sine of the floating point number
 */
float asinhf(float x) {
	return __builtin_asinhf(x);
}

#endif
