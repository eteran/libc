
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: __elibc_tan
//----------------------------------------------------------------------------*/
static double __elibc_tan(double x) {

	/* TODO(eteran): account for possible overflow */
	const double cos_val = cos(x);
	if (cos_val != 0.0) {
		return sin(x) / cos_val;
	} else {
		errno = EDOM;
		return 0.0;
	}
}

/*------------------------------------------------------------------------------
// Name: tan
//----------------------------------------------------------------------------*/
double tan(double x) {
#ifndef __FAST_MATH__
	if (isnan(x)) {
		errno = EDOM;
		return x;
	}

	if (isinf(x)) {
		errno = EDOM;
		return NAN;
	}
#endif

	return __elibc_tan(x);
}
