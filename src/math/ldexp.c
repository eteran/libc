
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*
        If the result underflows, a range error occurs, and zero is returned.

        If  the  result overflows, a range error occurs, and the functions
   return HUGE_VAL, HUGE_VALF, or HUGE_VALL, respectively, with a sign the same
   as x.


        Range error, overflow
        errno is set to ERANGE.  An overflow floating-point exception
   (FE_OVERFLOW) is raised.

        Range error, underflow
        errno is set to ERANGE.  An underflow floating-point exception
   (FE_UNDERFLOW) is raised.
*/

/*------------------------------------------------------------------------------
// Name: ldexp
// Desc: On success, these functions return x * (2^exp).
//----------------------------------------------------------------------------*/
_ENSURE_INLINE static double __elibc_ldexp(double x, int exp) {
	/* TODO(eteran): detect overflow/underflow */
	if (exp > 0) {
		const double y = pow(2, exp);
		return x * y;
	} else {
		const double y = pow(2, -exp);
		return x * (1 / y);
	}
}

/*------------------------------------------------------------------------------
// Name: ldexp
// Desc: On success, these functions return x * (2^exp).
//----------------------------------------------------------------------------*/
double ldexp(double x, int exp) {
#ifndef __FAST_MATH__
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
	return __elibc_ldexp(x, exp);
}

#endif
