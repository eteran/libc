
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Computes the arc cosine of a floating point number.
 *
 * @param x The value for which to compute the arc cosine.
 * @return The arc cosine of the input value.
 */
long double acosl(long double x) {
	return __builtin_acosl(x);
}

#endif
