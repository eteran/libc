
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: fmax
//----------------------------------------------------------------------------*/
double fmax(double x, double y) {
#ifndef __FAST_MATH__
	if(isnan(x)) {
		return y;
	}

	if(isnan(y)) {
		return x;
	}
#endif
	return x > y ? x : y;
}
