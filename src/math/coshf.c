
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: __elibc_coshf
//----------------------------------------------------------------------------*/
static float __elibc_coshf(float x) { return (expf(x) + expf(-x)) / 2; }

/*------------------------------------------------------------------------------
// Name: coshf
//----------------------------------------------------------------------------*/
float coshf(float x) {
#ifndef __FAST_MATH__
	if (isnan(x)) {
		return x;
	}

	if (x == 0.0 || x == -0.0) {
		return 1;
	}

	if (isinf(x)) {
		return copysignf(x, 1);
	}
#endif

	return __elibc_coshf(x);
}

#endif
