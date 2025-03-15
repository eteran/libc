
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the natural logarithm of a floating point number
 *
 * @param x the floating point number to compute the natural logarithm of
 * @return the natural logarithm of the floating point number
 */
float logf(float x) {
	return __builtin_logf(x);
}

#endif
