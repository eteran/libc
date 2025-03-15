
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the integer value of a floating point number
 *
 * @param x the floating point number to compute the integer value of
 * @return the integer value of the floating point
 */
long double truncl(long double x) {
#ifndef __FAST_MATH__
	if (isnan(x)) {
		return x;
	}

	if (x == 0.0 || x == -0.0) {
		return x;
	}

	if (isinf(x)) {
		return x;
	}
#endif

	return __builtin_truncl(x);
}

#endif
