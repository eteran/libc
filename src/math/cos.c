
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: __elibc_cos
//----------------------------------------------------------------------------*/
static double __elibc_cos(double x) { return sin(x + (M_PI / 2.0)); }

/*------------------------------------------------------------------------------
// Name: cos
//----------------------------------------------------------------------------*/
double cos(double x) {

#ifndef __FAST_MATH__
	if (isnan(x)) {
		return x;
	}

	if (isinf(x)) {
		errno = EDOM;
		return NAN;
	}
#endif

	return __elibc_cos(x);
}

#endif
