
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: __elibc_fmin
//----------------------------------------------------------------------------*/
_ALWAYS_INLINE _INLINE static double __elibc_fmin(double x, double y) {
	return x < y ? x : y;
}

/*------------------------------------------------------------------------------
// Name: fmin
//----------------------------------------------------------------------------*/
double fmin(double x, double y) {
#ifndef __FAST_MATH__
	if (isnan(x)) {
		return y;
	}

	if (isnan(y)) {
		return x;
	}
#endif
	return __elibc_fmin(x, y);
}

#endif
