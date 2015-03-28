
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: tanh
//----------------------------------------------------------------------------*/
double tanh(double x) {

#ifndef __FAST_MATH__
	if(isnan(x)) {
		return x;
	}

	if(x == 0.0 || x == -0.0) {
		return x;
	}

	if(isinf(x)) {
		return copysign(1, x);
	}
#endif

	return sinh(x) / cosh(x);
}
