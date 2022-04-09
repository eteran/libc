
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: __elibc_fminf
//----------------------------------------------------------------------------*/
static float __elibc_fminf(float x, float y) {
	return x < y ? x : y;
}

/*------------------------------------------------------------------------------
// Name: fminf
//----------------------------------------------------------------------------*/
float fminf(float x, float y) {
#ifndef __FAST_MATH__
	if (isnan(x)) {
		return y;
	}

	if (isnan(y)) {
		return x;
	}
#endif
	return __elibc_fminf(x, y);
}

#endif
