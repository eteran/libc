
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the hyperbolic arc tangent tangent of a floating point number
 *
 * @param x the floating point number to compute the hyperbolic arc tangent of
 * @return the hyperbolic arc tangent of the floating point number
 */
double atanh(double x) {
	return __builtin_atanh(x);
}

#endif
