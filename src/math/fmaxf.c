
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: fmaxf
//----------------------------------------------------------------------------*/
float fmaxf(float x, float y) {
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
