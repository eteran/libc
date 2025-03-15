
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the value of 2 raised to the power of a floating point number
 *
 * @param x the floating point number to compute the value of 2 raised to the power of
 * @return the value of 2 raised to the power of the floating point number
 */
static long double __elibc_exp2l(long double x) {
	return powl(2, x);
}

/**
 * @brief Compute the value of 2 raised to the power of a floating point number
 *
 * @param x the floating point number to compute the value of 2 raised to the power of
 * @return the value of 2 raised to the power of the floating point number
 */
long double exp2l(long double x) {
#ifndef __FAST_MATH__
	if (isnan(x)) {
		return x;
	}

	if (isinf(x)) {
		if (x > 0.0) {
			return x;
		} else {
			return 0.0;
		}
	}

	/* TODO(eteran): handle underflow/overflow */
#endif

	return __elibc_exp2l(x);
}

#endif
