
#define __ELIBC_SOURCE
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: __elibc_pow
//----------------------------------------------------------------------------*/
static double __elibc_pow(double x, double y) {
	double ret = 1;
	long int i;
	const long int y_int = (long int)y;

	for (i = 0; i < y_int; ++i) {
		ret *= x;
	}

	return ret;
}

/*------------------------------------------------------------------------------
// Name: pow
//----------------------------------------------------------------------------*/
double pow(double x, double y) {

#ifndef __FAST_MATH__
	if (x == 1.0 || y == 0.0) {
		return 1.0;
	}

	/* TODO(eteran):
	 *
	 * If x is a finite value less than 0, and y is a finite non-integer, a domain
	 error occurs, and a NaN is returned.
	 * If the result overflows, a range error occurs, and the functions return
	 HUGE_VAL, HUGE_VALF, or HUGE_VALL, respectively, with the mathematically cor‐
	   rect sign.
	 * If result underflows, and is not representable, a range error occurs, and
	 0.0 is returned.
	 * If x is +0 (-0), and y is an odd integer greater than 0, the result is +0
	 (-0)
	 * If x is 0, and y greater than 0 and not an odd integer, the result is +0.
	 * If x is -1, and y is positive infinity or negative infinity, the result
	 is 1.0.
	 * If the absolute value of x is less than 1, and y is negative infinity, the
	 result is positive infinity
	 * If the absolute value of x is greater than 1, and y is negative infinity,
	 the result is +0.
	 * If the absolute value of x is less than 1, and y is positive infinity, the
	 result is +0.
	 * If the absolute value of x is greater than 1, and y is positive infinity,
	 the result is positive infinity.
	 * If x is negative infinity, and y is an odd integer less than 0, the result
	 is -0.
	 * If x is negative infinity, and y less than 0 and not an odd integer, the
	 result is +0.
	 * If x is negative infinity, and y is an odd integer greater than 0, the
	 result is negative infinity.
	 * If x is negative infinity, and y greater than 0 and not an odd integer, the
	 result is positive infinity.
	 * If x is positive infinity, and y less than 0, the result is +0.
	 * If x is positive infinity, and y greater than 0, the result is positive
	 infinity.
	 * If x is +0 or -0, and y is an odd integer less than 0, a pole error occurs
	 and HUGE_VAL, HUGE_VALF, or HUGE_VALL, is returned, with the same sign as x.
	 * If x is +0 or -0, and y is less than 0 and not an odd integer, a pole error
	 occurs and +HUGE_VAL, +HUGE_VALF, or +HUGE_VALL, is returned.
	 */

	if (isnan(x)) {
		return x;
	}

	if (isnan(y)) {
		return y;
	}
#endif

	return __elibc_pow(x, y);
}

#endif
