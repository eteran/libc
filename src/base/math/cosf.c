
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: __elibc_cosf
//----------------------------------------------------------------------------*/
static float __elibc_cosf(float x) {
	return sinf(x + (M_PIf / 2.0f));
}

/*------------------------------------------------------------------------------
// Name: cosf
//----------------------------------------------------------------------------*/
float cosf(float x) {

#ifndef __FAST_MATH__
	if (isnan(x)) {
		return x;
	}

	if (isinf(x)) {
		errno = EDOM;
		return NAN;
	}
#endif

	return __elibc_cosf(x);
}

#endif
