
#define _ELIBC_SOURCE

#include <math.h>

#ifdef _HAS_FPU

/*
		If the result underflows, a range error occurs, and zero is returned.

		If  the  result overflows, a range error occurs, and the functions
   return HUGE_VAL, HUGE_VALF, or HUGE_VALL, respectively, with a sign the same
   as x.


		Range error, overflow
		errno is set to ERANGE.  An overflow floating point exception
   (FE_OVERFLOW) is raised.

		Range error, underflow
		errno is set to ERANGE.  An underflow floating point exception
   (FE_UNDERFLOW) is raised.
*/

/**
 * @brief Multiply a floating point value by the 2 raised to the exp power.
 *
 * @param x the floating point number to compute the value of
 * @param exp the exponent to raise 2 to
 * @return the value of the floating point number multiplied by 2 raised to the power of exp
 * @note This function does not handle special cases such as NaN or infinity
 *       gracefully.
 */
_ALWAYS_INLINE _INLINE long double __elibc_ldexpl(long double x, int exp) {
	/* TODO(eteran): detect overflow/underflow */
	if (exp > 0) {
		const long double y = powl(2, exp);
		return x * y;
	} else {
		const long double y = powl(2, -exp);
		return x * (1 / y);
	}
}

/**
 * @brief Multiply a floating point value by the 2 raised to the exp power.
 *
 * @param x the floating point number to compute the value of
 * @param exp the exponent to raise 2 to
 * @return the value of the floating point number multiplied by 2 raised to the power of exp
 */
long double ldexpl(long double x, int exp) {
#if !defined(__FAST_MATH__)
	if (exp == 0) {
		/* If exp is zero, then x is returned. */
		return x;
	}

	if (isnan(x)) {
		/* If x is a NaN, a NaN is returned. */
		return x;
	}

	if (isinf(x)) {
		/* If x is a NaN, a NaN is returned. */
		return x;
	}
#endif

	return __elibc_ldexpl(x, exp);
}

#endif
