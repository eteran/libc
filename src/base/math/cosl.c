
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the cosine of a floating point number
 *
 * @param x the floating point number to compute the cosine of
 * @return the cosine of the floating point number
 */
long double cosl(long double x) {
	return __builtin_cosl(x);
}

#endif
