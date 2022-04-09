
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: __elibc_fmax
//----------------------------------------------------------------------------*/
static double __elibc_fmax(double x, double y) { return x > y ? x : y; }

/*------------------------------------------------------------------------------
// Name: fmax
//----------------------------------------------------------------------------*/
double fmax(double x, double y) {
#ifndef __FAST_MATH__
	if (isnan(x)) {
		return y;
	}

	if (isnan(y)) {
		return x;
	}
#endif
	return __elibc_fmax(x, y);
}

#endif
