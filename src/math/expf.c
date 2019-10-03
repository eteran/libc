
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: _elibc_expf
//----------------------------------------------------------------------------*/
static float _elibc_expf(float x) {
	return powf(M_E, x);
}

/*------------------------------------------------------------------------------
// Name: expf
//----------------------------------------------------------------------------*/
float expf(float x) {
#ifndef __FAST_MATH__
	if (isnan(x)) {
		return x;
	}

	if (isinf(x)) {
		if (x > 0.0) {
			return x;
		} else {
			return 0.0;
		}
	}

	/* TODO(eteran): handle underflow/overflow */
#endif

	return _elibc_expf(x);
}
