
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Computes the inverse hyperbolic cosine of a given value.
 *
 * @param x The value for which to compute the inverse hyperbolic cosine.
 * @return long double The inverse hyperbolic cosine of the input value.
 */
long double acoshl(long double x) {
	return __builtin_acoshl(x);
}

#endif
