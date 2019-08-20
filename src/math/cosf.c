
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: cosf
//----------------------------------------------------------------------------*/
float cosf(float x) {

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

	return sinf(x + (M_PI / 2.0));
}
