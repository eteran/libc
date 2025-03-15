
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the hyperbolic sine of a floating point number
 *
 * @param x the floating point number to compute the hyperbolic sine of
 * @return the hyperbolic sine of the floating point number
 */
float sinhf(float x) {
	return __builtin_sinhf(x);
}

#endif
