
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: sinh
//----------------------------------------------------------------------------*/
double sinh(double x) {

#ifndef __FAST_MATH__
	if(isnan(x)) {
		return x;
	}

	if(x == 0.0 || x == -0.0) {
		return x;
	}

	if(isinf(x)) {
		return x;
	}
#endif

	return (exp(x) - exp(-x)) / 2;
}
