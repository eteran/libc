
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Computes the hyperbolic arc cosine of a floating point number.
 *
 * @param x The value for which to compute the hyperbolic arc cosine.
 * @return The hyperbolic arc cosine of the input value.
 */
float acoshf(float x) {
	return __builtin_acoshf(x);
}

#endif
