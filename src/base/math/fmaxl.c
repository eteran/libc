
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the maximum of two floating point numbers
 *
 * @param x the first floating point number
 * @param y the second floating point number
 * @return the maximum of the two floating point numbers
 * @note This function does not handle special cases such as NaN or infinity
 *       gracefully.
 */
_ALWAYS_INLINE _INLINE static long double __elibc_fmaxl(long double x, long double y) {
	return x > y ? x : y;
}

/**
 * @brief Compute the maximum of two floating point numbers
 *
 * @param x the first floating point number
 * @param y the second floating point number
 * @return the maximum of the two floating point numbers
 */
long double fmaxl(long double x, long double y) {
#ifndef __FAST_MATH__
	if (isnan(x)) {
		return y;
	}

	if (isnan(y)) {
		return x;
	}
#endif
	return __elibc_fmaxl(x, y);
}

#endif
