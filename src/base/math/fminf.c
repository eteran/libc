
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the minimum of two floating point numbers
 *
 * @param x the first floating point number
 * @param y the second floating point number
 * @return the minimum of the two floating point numbers
 * @note This function does not handle special cases such as NaN or infinity
 *       gracefully.
 */
_ALWAYS_INLINE _INLINE static float __elibc_fminf(float x, float y) {
	return x < y ? x : y;
}

/**
 * @brief Compute the minimum of two floating point numbers
 *
 * @param x the first floating point number
 * @param y the second floating point number
 * @return the minimum of the two floating point numbers
 */
float fminf(float x, float y) {
#ifndef __FAST_MATH__
	if (isnan(x)) {
		return y;
	}

	if (isnan(y)) {
		return x;
	}
#endif
	return __elibc_fminf(x, y);
}

#endif
