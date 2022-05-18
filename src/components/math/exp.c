
#define _ELIBC_SOURCE
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: __elibc_exp
//----------------------------------------------------------------------------*/
_ALWAYS_INLINE _INLINE static double __elibc_exp(double x) {
	return pow(M_E, x);
}

/*------------------------------------------------------------------------------
// Name: exp
//----------------------------------------------------------------------------*/
double exp(double x) {

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

	return __elibc_exp(x);
}

#endif
