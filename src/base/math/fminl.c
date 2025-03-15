
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
 */
static long double __elibc_fminl(long double x, long double y) {
	return x < y ? x : y;
}

/**
 * @brief Compute the minimum of two floating point numbers
 *
 * @param x the first floating point number
 * @param y the second floating point number
 * @return the minimum of the two floating point numbers
 */
long double fminl(long double x, long double y) {
#ifndef __FAST_MATH__
	if (isnan(x)) {
		return y;
	}

	if (isnan(y)) {
		return x;
	}
#endif
	return __elibc_fminl(x, y);
}

#endif
