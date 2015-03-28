
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: cos
//----------------------------------------------------------------------------*/
double cos(double x) {

#ifndef __FAST_MATH__
#if 0
	if(isnan(x)) {
		return x;
	}

	if(isinf(x)) {
		errno = EDOM;
		return NAN;
	}
#endif
#endif

	return sin(x + (M_PI / 2.0));
}
