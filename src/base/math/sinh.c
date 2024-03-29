
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: __elibc_sinh
//----------------------------------------------------------------------------*/
_ALWAYS_INLINE _INLINE static double __elibc_sinh(double x) {
	return (exp(x) - exp(-x)) / 2;
}

/*------------------------------------------------------------------------------
// Name: sinh
//----------------------------------------------------------------------------*/
double sinh(double x) {

#ifndef __FAST_MATH__
	if (isnan(x)) {
		return x;
	}

	if (x == 0.0 || x == -0.0) {
		return x;
	}

	if (isinf(x)) {
		return x;
	}
#endif

	return __elibc_sinh(x);
}

#endif
