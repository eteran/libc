
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the square root of a floating point number
 *
 * @param x the floating point number to compute the square root of
 * @return the square root of the floating point
 */
float sqrtf(float x) {
	return __builtin_sqrtf(x);
}

#endif
