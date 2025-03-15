
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the base-10 logarithm of a floating point number
 *
 * @param x the floating point number to compute the base-10 logarithm of
 * @return the base-10 logarithm of the floating point number
 */
long double log10l(long double x) {
	return __builtin_log10l(x);
}

#endif
