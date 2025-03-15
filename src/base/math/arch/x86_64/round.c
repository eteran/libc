
#define _ELIBC_SOURCE
#include <fenv.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Computes the nearest integer value to x, rounding halfway cases away from zero,
 * regardless of the current rounding mode.
 *
 * @param x the floating point number to round
 * @return the rounded floating point number
 * @note This function does not handle special cases such as NaN or infinity
 *       gracefully.
 */
_ALWAYS_INLINE _INLINE static double __elibc_round(double x) {
	double value;
	const int save_round = fesetround(FE_TONEAREST);
	__asm__ __volatile__("frndint"
						 : "=t"(value)
						 : "0"(x));
	fesetround(save_round);
	return value;
}

/**
 * @brief Computes the nearest integer value to x, rounding halfway cases away from zero,
 * regardless of the current rounding mode.
 *
 * @param x the floating point number to round
 * @return the rounded floating point number
 */
double round(double x) {
	return __elibc_round(x);
}

#endif
