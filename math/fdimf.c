
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: fdimf
//----------------------------------------------------------------------------*/
float fdimf(float x, float y) {
#ifndef __FAST_MATH__
	if(isnan(x)) {
		return x;
	}

	if(isnan(y)) {
		return y;
	}
#endif
	return fmaxf(x - y, 0);
}
