
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: __elibc_fdiml
//----------------------------------------------------------------------------*/
static long double __elibc_fdiml(long double x, long double y) {
	return fmaxl(x - y, 0);
}

/*------------------------------------------------------------------------------
// Name: fdiml
//----------------------------------------------------------------------------*/
long double fdiml(long double x, long double y) {
#ifndef __FAST_MATH__
	if (isnan(x)) {
		return x;
	}

	if (isnan(y)) {
		return y;
	}
#endif
	return __elibc_fdiml(x, y);
}

#endif
