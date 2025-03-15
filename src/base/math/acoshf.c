
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
float acoshf(float x) {
	return __builtin_acoshf(x);
}

#endif
