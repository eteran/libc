
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

#define TAYLOR_ITERATIONS 20

/* TODO(eteran): we should probably use bitwise operations to inspect
 * the exponent and mantissa of the floating point number to determine
 * if it is an integer.
 */
#define IS_INTEGER(value) ((value) == (double)(long int)(value))

/**
 * @brief Compute the value of e raised to the power of x using a taylor series
 *
 * @param n the number of iterations to use in the taylor series
 * @param x the exponent to raise e to
 * @return the value of e raised to the power of x
 * @note This function does not handle special cases such as NaN or infinity
 *       gracefully.
 */
_ALWAYS_INLINE _INLINE static double __elibc_pow_e(int n, double x) {
	double sum = 1.0F;
	int i      = n - 1;

	for (; i > 0; --i) {
		sum = 1 + x * sum / i;
	}

	return sum;
}

/**
 * @brief Raise a floating point number to the power of another
 *
 * @param x the base
 * @param y the exponent
 * @return the value of x raised to the power of y
 * @note This function does not handle special cases such as NaN or infinity
 *       gracefully.
 */
_ALWAYS_INLINE _INLINE static double __elibc_pow(double base, double exponent) {

	/* for integer powers, lets just keep it simple */
	if (exponent > 0.0 && IS_INTEGER(exponent)) {
		double ret = 1;
		long int i;
		const long int y_int = (long int)exponent;

		for (i = 0; i < y_int; ++i) {
			ret *= base;
		}

		return ret;
	} else {
		/* b^x == e^(ln(b) * x) */
		return __elibc_pow_e(TAYLOR_ITERATIONS, __elibc_log(base) * exponent);
	}
}

/**
 * @brief Raise a floating point number to the power of another
 *
 * @param x the base
 * @param y the exponent
 * @return the value of x raised to the power of y
 */
double pow(double base, double exponent) {

#if !defined(__FAST_MATH__)

	/* If base is finite and negative and exponent is finite and non-integer, a domain error occurs
	 * and a range error may occur.*/
	if (isfinite(base) && base < 0.0 && isfinite(exponent) && IS_INTEGER(exponent)) {
		errno = EDOM;
		return 0.0;
	}

	/* If base is zero and exponent is negative, a domain error or a pole error may occur.*/
	if (base == 0.0 && exponent < 0.0) {
		errno = EDOM;
		return 0.0;
	}

	/* If base is zero and exponent is zero, a domain error may occur. */
	if (base == 0.0 && exponent == 0.0) {
		errno = EDOM;
		return 0.0;
	}

#if 0
If the implementation supports IEEE floating point arithmetic (IEC 60559),
pow(+0, exponent), where exponent is a negative odd integer, returns +∞ and raises FE_DIVBYZERO
pow(-0, exponent), where exponent is a negative odd integer, returns -∞ and raises FE_DIVBYZERO
pow(±0, exponent), where exponent is negative, finite, and is an even integer or a non-integer, returns +∞ and raises FE_DIVBYZERO
pow(±0, -∞) returns +∞ and may raise FE_DIVBYZERO (until C23)
pow(+0, exponent), where exponent is a positive odd integer, returns +0
pow(-0, exponent), where exponent is a positive odd integer, returns -0
pow(±0, exponent), where exponent is positive non-integer or a positive even integer, returns +0
pow(-1, ±∞) returns 1
pow(+1, exponent) returns 1 for any exponent, even when exponent is NaN
pow(base, ±0) returns 1 for any base, even when base is NaN
pow(base, exponent) returns NaN and raises FE_INVALID if base is finite and negative and exponent is finite and non-integer.
pow(base, -∞) returns +∞ for any |base|<1
pow(base, -∞) returns +0 for any |base|>1
pow(base, +∞) returns +0 for any |base|<1
pow(base, +∞) returns +∞ for any |base|>1
pow(-∞, exponent) returns -0 if exponent is a negative odd integer
pow(-∞, exponent) returns +0 if exponent is a negative non-integer or negative even integer
pow(-∞, exponent) returns -∞ if exponent is a positive odd integer
pow(-∞, exponent) returns +∞ if exponent is a positive non-integer or positive even integer
pow(+∞, exponent) returns +0 for any negative exponent
pow(+∞, exponent) returns +∞ for any positive exponent
except where specified above, if any argument is NaN, NaN is returned
#endif

	if (base == 1.0 || exponent == 0.0) {
		return 1.0;
	}

	if (isnan(base)) {
		return base;
	}

	if (isnan(exponent)) {
		return exponent;
	}
#endif

	return __elibc_pow(base, exponent);
}

#endif
