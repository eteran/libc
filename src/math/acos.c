
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: __elibc_acos
//----------------------------------------------------------------------------*/
static double __elibc_acos(double x) {
	return (M_PI / 2) - asin(x);
}

/*------------------------------------------------------------------------------
// Name: acos
//----------------------------------------------------------------------------*/
double acos(double x) {

#ifndef __FAST_MATH__
	if (isnan(x)) {
		return x;
	}

	if (x == 1.0) {
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

	return __elibc_acos(x);
}
