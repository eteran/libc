
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: fdim
//----------------------------------------------------------------------------*/
double fdim(double x, double y) {
#ifndef __FAST_MATH__
	if(isnan(x)) {
		return x;
	}

	if(isnan(y)) {
		return y;
	}
#endif
	return fmax(x - y, 0);
}
