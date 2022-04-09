
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: asinf
//----------------------------------------------------------------------------*/
static float __elibc_asinf(float x) {
	return atanf(x / sqrtf(1 - (x * x)));
}

/*------------------------------------------------------------------------------
// Name: asinf
//----------------------------------------------------------------------------*/
float asinf(float x) {
#ifndef __FAST_MATH__
	if (isnan(x)) {
		return x;
	}

	if (x == 0.0) {
		return x;
	}

	if (x < -1 || x > 1) {
		errno = EDOM;
		return NAN;
	}
#endif

	return __elibc_asinf(x);
}

#endif
