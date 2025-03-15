
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the natural logarithm of 1 plus a floating point number
 *
 * @param x the floating point number to compute the natural logarithm of
 * @return the natural logarithm of 1 plus the floating point number
 */
long double log1pl(long double x) {
	return __builtin_log1pl(x);
}

#endif
