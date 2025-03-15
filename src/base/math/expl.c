
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Compute the value of e raised to the power of a floating point number
 *
 * @param x the floating point number to compute the value of e raised to the power of
 * @return the value of e raised to the power of the floating point number
 * @note This function does not handle special cases such as NaN or infinity
 *       gracefully.
 */
_ALWAYS_INLINE _INLINE static long double __elibc_expl(long double x) {
	return powl(M_E, x);
}

/**
 * @brief Compute the value of e raised to the power of a floating point number
 *
 * @param x the floating point number to compute the value of e raised to the power of
 * @return the value of e raised to the power of the floating point number
 */
long double expl(long double x) {
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

	return __elibc_expl(x);
}

#endif
