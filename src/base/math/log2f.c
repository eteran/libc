
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the base-2 logarithm of a floating point number
 *
 * @param x the floating point number to compute the base-2 logarithm of
 * @return the base-2 logarithm of the floating point number
 */
float log2f(float x) {
	return __builtin_log2f(x);
}

#endif
