
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: acosf
//----------------------------------------------------------------------------*/
float acosf(float x) {
#ifndef __FAST_MATH__
	if(isnan(x)) {
		return x;
	}

	if(x == 1.0) {
		return 0.0;
	}

	if(isinf(x)) {
		errno = EDOM;
		return NAN;
	}

	if(x < -1 || x > 1) {
		errno = EDOM;
		return NAN;
	}
#endif

	return (M_PI / 2) - asinf(x);
}
