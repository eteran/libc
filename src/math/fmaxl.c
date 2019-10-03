
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: __elibc_fmaxl
//----------------------------------------------------------------------------*/
static long double __elibc_fmaxl(long double x, long double y) {
	return x > y ? x : y;
}

/*------------------------------------------------------------------------------
// Name: fmaxl
//----------------------------------------------------------------------------*/
long double fmaxl(long double x, long double y) {
#ifndef __FAST_MATH__
	if (isnan(x)) {
		return y;
	}

	if (isnan(y)) {
		return x;
	}
#endif
	return __elibc_fmaxl(x, y);
}
