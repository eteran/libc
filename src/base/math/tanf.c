
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the tangent of a floating point number
 *
 * @param x the floating point number to compute the tangent of
 * @return the tangent of the floating point number
 */
float tanf(float x) {
	return __builtin_tanf(x);
}

#endif
