
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: __elibc_fmaxf
//----------------------------------------------------------------------------*/
static float __elibc_fmaxf(float x, float y) {
	return x > y ? x : y;
}

/*------------------------------------------------------------------------------
// Name: fmaxf
//----------------------------------------------------------------------------*/
float fmaxf(float x, float y) {
#ifndef __FAST_MATH__
	if (isnan(x)) {
		return y;
	}

	if (isnan(y)) {
		return x;
	}
#endif
	return __elibc_fmaxf(x, y);
}
