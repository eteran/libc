
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the positive difference between two floating point numbers
 *
 * @param x the first floating point number
 * @param y the second floating point number
 * @return the positive difference between the two floating point numbers
 */
static long double __elibc_fdiml(long double x, long double y) {
	return fmaxl(x - y, 0);
}

/**
 * @brief Compute the positive difference between two floating point numbers
 *
 * @param x the first floating point number
 * @param y the second floating point number
 * @return the positive difference between the two floating point numbers
 */
long double fdiml(long double x, long double y) {
#ifndef __FAST_MATH__
	if (isnan(x)) {
		return x;
	}

	if (isnan(y)) {
		return y;
	}
#endif
	return __elibc_fdiml(x, y);
}

#endif
