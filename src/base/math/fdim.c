
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the positive difference between two floating point numbers
 *
 * @param x the first floating point number
 * @param y the second floating point number
 * @return the positive difference between the two floating point numbers
 * @note This function does not handle special cases such as NaN or infinity
 *       gracefully.
 */
_ALWAYS_INLINE _INLINE static double __elibc_fdim(double x, double y) {
	return fmax(x - y, 0);
}

/**
 * @brief Compute the positive difference between two floating point numbers
 *
 * @param x the first floating point number
 * @param y the second floating point number
 * @return the positive difference between the two floating point numbers
 */
double fdim(double x, double y) {
#if !defined(__FAST_MATH__)
	if (isnan(x)) {
		return x;
	}

	if (isnan(y)) {
		return y;
	}
#endif
	return __elibc_fdim(x, y);
}

#endif
