
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: asin
//----------------------------------------------------------------------------*/
double asin(double x) {

#ifndef __FAST_MATH__
	if(isnan(x)) {
		return x;
	}

	if(x == 0.0) {
		return x;
	}

	if(x < -1 || x > 1) {
		errno = EDOM;
		return NAN;
	}
#endif

	return atan(x / sqrt(1 - (x * x)));
}
