
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: __elibc_tan
//----------------------------------------------------------------------------*/
static double __elibc_tan(double x) {
	double ret = 0.0;
	const double cos_val = cos(x);
	if(cos_val != 0.0) {
		ret = sin(x) / cos_val;
	} else {
		errno = EDOM;
	}

	/* TODO: account for possible overflow */
	return ret;
}

/*------------------------------------------------------------------------------
// Name: tan
//----------------------------------------------------------------------------*/
double tan(double x) {
#ifndef __FAST_MATH__
	if(isnan(x)) {
		errno = EDOM;
		return x;
	}

	if(isinf(x)) {
		errno = EDOM;
		return NAN;
	}
#endif

	return __elibc_tan(x);
}
