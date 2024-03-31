
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: _elibc_expf
//----------------------------------------------------------------------------*/
static float _elibc_expf(float x) {
	return powf(M_Ef, x);
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
			return 0.0f;
		}
	}

	/* TODO(eteran): handle underflow/overflow */
#endif

	return _elibc_expf(x);
}

#endif
