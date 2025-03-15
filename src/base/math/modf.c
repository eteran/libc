
#define _ELIBC_SOURCE
#include <assert.h>
#include <math.h>

#ifdef _HAS_FPU

/**
 * @brief Split a floating point value into its integer and fractional parts
 *
 * @param arg the floating point value to split
 * @param iptr a pointer to store the integer part of the floating point value
 * @return the fractional part of the floating point value
 * @note This function does not handle special cases such as NaN or infinity
 *       gracefully.
 */
_ALWAYS_INLINE _INLINE static double __elibc_modf(double arg, double *iptr) {
	int sign = 1;
	double i_portion;

	assert(iptr);

	if (arg < 0) {
		arg  = -arg;
		sign = -1;
	}

	i_portion = floor(arg);
	*iptr     = (i_portion * sign);
	return copysign(isinf(arg) ? 0.0 : arg - (*iptr), arg);
}

/**
 * @brief Split a floating point value into its integer and fractional parts
 *
 * @param arg the floating point value to split
 * @param iptr a pointer to store the integer part of the floating point value
 * @return the fractional part of the floating point value
 */
double modf(double arg, double *iptr) {
	return __elibc_modf(arg, iptr);
}

#endif
