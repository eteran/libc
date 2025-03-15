
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Computes the inverse hyperbolic cosine of a given value.
 *
 * @param x The value for which to compute the inverse hyperbolic cosine.
 * @return The inverse hyperbolic cosine of the input value.
 */
double acosh(double x) {
	return __builtin_acosh(x);
}

#endif
