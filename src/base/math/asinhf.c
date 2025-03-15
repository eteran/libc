
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the inverse hyperbolic sine of a floating point number
 *
 * @param x the floating point number to compute the inverse hyperbolic sine of
 * @return the inverse hyperbolic sine of the floating point number
 */
float asinhf(float x) {
	return __builtin_asinhf(x);
}

#endif
