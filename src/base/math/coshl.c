
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the hyperbolic cosine of a floating point number
 *
 * @param x the floating point number to compute the hyperbolic cosine of
 * @return the hyperbolic cosine of the floating point number
 */
long double coshl(long double x) {
	return __builtin_coshl(x);
}

#endif
