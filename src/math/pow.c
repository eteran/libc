
#define _ELIBC_SOURCE
#include <math.h>

#ifdef _HAS_FPU

/* TODO(eteran): actually handling this correctly, including non-integers and proper error handling
 * is COMPLEX, see: https://en.cppreference.com/w/c/numeric/math/pow */

/*------------------------------------------------------------------------------
// Name: __elibc_pow
//----------------------------------------------------------------------------*/
_ALWAYS_INLINE static double __elibc_pow(double x, double y) {
	double ret = 1;
	long int i;
	const long int y_int = (long int)y;

	for (i = 0; i < y_int; ++i) {
		ret *= x;
	}

	return ret;
}

/*------------------------------------------------------------------------------
// Name: pow
//----------------------------------------------------------------------------*/
double pow(double x, double y) {

#ifndef __FAST_MATH__
	if (x == 1.0 || y == 0.0) {
		return 1.0;
	}

	if (isnan(x)) {
		return x;
	}

	if (isnan(y)) {
		return y;
	}
#endif

	return __elibc_pow(x, y);
}

#endif
