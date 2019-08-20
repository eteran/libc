
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: fdiml
//----------------------------------------------------------------------------*/
long double fdiml(long double x, long double y) {
#ifndef __FAST_MATH__
	if(isnan(x)) {
		return x;
	}

	if(isnan(y)) {
		return y;
	}
#endif
	return fmaxl(x - y, 0);
}
