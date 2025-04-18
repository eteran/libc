

#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the nearest integer not greater in magnitude than num.
 *
 * @param x the floating point number to compute the integer value of
 * @return the integer value of the floating point
 */
float truncf(float x) {
#if !defined(__FAST_MATH__)
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

	return __builtin_truncf(x);
}

#endif
