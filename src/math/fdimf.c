
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: __elibc_fdimf
//----------------------------------------------------------------------------*/
static float __elibc_fdimf(float x, float y) {
	return fmaxf(x - y, 0);
}

/*------------------------------------------------------------------------------
// Name: fdimf
//----------------------------------------------------------------------------*/
float fdimf(float x, float y) {
#ifndef __FAST_MATH__
	if (isnan(x)) {
		return x;
	}

	if (isnan(y)) {
		return y;
	}
#endif
	return __elibc_fdimf(x, y);
}

#endif
