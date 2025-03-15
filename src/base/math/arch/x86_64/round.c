
#define _ELIBC_SOURCE
#include <fenv.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Round a floating point number to the nearest integer, but round halfway cases away from zero
 * (regardless of the current rounding direction
 *
 * @param x the floating point number to round
 * @return the rounded floating point number
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
 * @brief Round a floating point number to the nearest integer, but round halfway cases away from zero
 * (regardless of the current rounding direction
 *
 * @param x the floating point number to round
 * @return the rounded floating point number
 */
double round(double x) {
	return __elibc_round(x);
}

#endif
