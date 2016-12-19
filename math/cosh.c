
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: cosh
//----------------------------------------------------------------------------*/
double cosh(double x) {

#ifndef __FAST_MATH__
	if(isnan(x)) {
		return x;
	}

	if(x == 0.0 || x == -0.0) {
		return 1;
	}

	if(isinf(x)) {
		return copysign(x, 1);
	}
#endif

	return (exp(x) + exp(-x)) / 2;
}
