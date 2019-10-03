
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: __elibc_cosh
//----------------------------------------------------------------------------*/
static double __elibc_cosh(double x) {
	return (exp(x) + exp(-x)) / 2;
}

/*------------------------------------------------------------------------------
// Name: cosh
//----------------------------------------------------------------------------*/
double cosh(double x) {
#ifndef __FAST_MATH__
	if (isnan(x)) {
		return x;
	}

	if (x == 0.0 || x == -0.0) {
		return 1;
	}

	if (isinf(x)) {
		return copysign(x, 1);
	}
#endif

	return __elibc_cosh(x);
}
