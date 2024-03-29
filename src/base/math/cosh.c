
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: __elibc_cosh
//----------------------------------------------------------------------------*/
_ALWAYS_INLINE _INLINE static double __elibc_cosh(double x) {
	return (exp(x) + exp(-x)) / 2;
}

/*------------------------------------------------------------------------------
// Name: cosh
//----------------------------------------------------------------------------*/
double cosh(double x) {
#ifndef __FAST_MATH__
	if (isnan(x)) {
		return x;
	}

	if (x == 0.0 || x == -0.0) {
		return 1;
	}

	if (isinf(x)) {
		return copysign(x, 1);
	}
#endif

	return __elibc_cosh(x);
}

#endif
