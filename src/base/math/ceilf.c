
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the smallest integer value not less than x
 *
 * @param x the floating point number to compute the smallest integer value not less than
 * @return the smallest integer value not less than x
 */
float ceilf(float x) {
	return __builtin_ceilf(x);
}

#endif
