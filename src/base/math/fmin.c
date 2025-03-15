
#define _ELIBC_SOURCE
#include <errno.h>
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
_ALWAYS_INLINE _INLINE static double __elibc_fmin(double x, double y) {
	return x < y ? x : y;
}

/**
 * @brief Compute the minimum of two floating point numbers
 *
 * @param x the first floating point number
 * @param y the second floating point number
 * @return the minimum of the two floating point numbers
 */
double fmin(double x, double y) {
#ifndef __FAST_MATH__
	if (isnan(x)) {
		return y;
	}

	if (isnan(y)) {
		return x;
	}
#endif
	return __elibc_fmin(x, y);
}

#endif
