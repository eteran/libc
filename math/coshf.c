
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: coshf
//----------------------------------------------------------------------------*/
float coshf(float x) {
#ifndef __FAST_MATH__
	if(isnan(x)) {
		return x;
	}

	if(x == 0.0 || x == -0.0) {
		return 1;
	}

	if(isinf(x)) {
		return copysignf(x, 1);
	}
#endif

	return (expf(x) + expf(-x)) / 2;
}
