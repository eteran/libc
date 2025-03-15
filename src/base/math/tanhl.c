
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the hyperbolic tangent of a floating point number
 *
 * @param x the floating point number to compute the hyperbolic tangent of
 * @return the hyperbolic tangent of the floating point number
 */
long double tanhl(long double x) {
	return __builtin_tanhl(x);
}

#endif
