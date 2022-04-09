
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: __elibc_asin
//----------------------------------------------------------------------------*/
static double __elibc_asin(double x) {
	return atan(x / sqrt(1 - (x * x)));
}

/*------------------------------------------------------------------------------
// Name: asin
//----------------------------------------------------------------------------*/
double asin(double x) {

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

	return __elibc_asin(x);
}

#endif
