
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Computes the arc cosine (inverse cosine) of a given value.
 *
 * @param x The value for which to compute the arc cosine.
 * @return double Returns the arc cosine of the input value.
 * @note This function uses the relationship between pi and arcsine to compute the arc cosine.
 */
_ALWAYS_INLINE _INLINE static double __elibc_acos(double x) {
	return (M_PI / 2) - asin(x);
}

/**
 * @brief Computes the arc cosine (inverse cosine) of a given value.
 *
 * @param x The value for which to compute the arc cosine.
 * @return double Returns the arc cosine of the input value.
 */
double acos(double x) {

#ifndef __FAST_MATH__
	if (isnan(x)) {
		return x;
	}

	if (x == 1.0) {
		return 0.0;
	}

	if (isinf(x)) {
		errno = EDOM;
		return NAN;
	}

	if (x < -1 || x > 1) {
		errno = EDOM;
		return NAN;
	}
#endif

	return __elibc_acos(x);
}

#endif
