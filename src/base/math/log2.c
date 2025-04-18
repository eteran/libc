
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the base-2 logarithm of a floating point number
 *
 * @param x the floating point number to compute the base-2 logarithm of
 * @return the base-2 logarithm of the floating point number
 */
double log2(double x) {
	return __builtin_log2(x);
}

#endif
