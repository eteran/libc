
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the inverse hyperbolic tangent tangent of a floating point number
 *
 * @param x the floating point number to compute the inverse hyperbolic tangent of
 * @return the inverse hyperbolic tangent of the floating point number
 */
double atanh(double x) {
	return __builtin_atanh(x);
}

#endif
