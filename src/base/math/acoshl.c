
#define _ELIBC_SOURCE
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Computes the hyperbolic arc cosine of a floating point number.
 *
 * @param x The value for which to compute the hyperbolic arc cosine.
 * @return The hyperbolic arc cosine of the input value.
 */
long double acoshl(long double x) {
	return __builtin_acoshl(x);
}

#endif
