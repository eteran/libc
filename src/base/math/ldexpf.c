
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
// Name: __elibc_ldexpf
// Desc: On success, these functions return x * (2^exp).
//----------------------------------------------------------------------------*/
static float __elibc_ldexpf(float x, int exp) {
	/* TODO(eteran): detect overflow/underflow */
	if (exp > 0) {
		const float y = powf(2, (float)exp);
		return x * y;
	} else {
		const float y = powf(2, (float)-exp);
		return x * (1 / y);
	}
}

/*------------------------------------------------------------------------------
// Name: ldexpf
// Desc: On success, these functions return x * (2^exp).
//----------------------------------------------------------------------------*/
float ldexpf(float x, int exp) {
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
	return __elibc_ldexpf(x, exp);
}

#endif
