
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: __elibc_fdim
//----------------------------------------------------------------------------*/
_ALWAYS_INLINE _INLINE static double __elibc_fdim(double x, double y) {
	return fmax(x - y, 0);
}

/*------------------------------------------------------------------------------
// Name: fdim
//----------------------------------------------------------------------------*/
double fdim(double x, double y) {
#ifndef __FAST_MATH__
	if (isnan(x)) {
		return x;
	}

	if (isnan(y)) {
		return y;
	}
#endif
	return __elibc_fdim(x, y);
}

#endif
