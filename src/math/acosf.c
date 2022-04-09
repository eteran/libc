
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: __elibc_acosf
//----------------------------------------------------------------------------*/
static float __elibc_acosf(float x) {
	return (M_PI / 2) - asinf(x);
}

/*------------------------------------------------------------------------------
// Name: acosf
//----------------------------------------------------------------------------*/
float acosf(float x) {
#ifndef __FAST_MATH__
	if (isnan(x)) {
		return x;
	}

	if (x == 1.0f) {
		return 0.0;
	}

	if (isinf(x)) {
		errno = EDOM;
		return NAN;
	}

	if (x < -1 || x > 1) {
		errno = EDOM;
		return NAN;
	}
#endif

	return __elibc_acosf(x);
}

#endif
