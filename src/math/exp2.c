
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: __elibc_exp2
//----------------------------------------------------------------------------*/
_ENSURE_INLINE static double __elibc_exp2(double x) {
	return pow(2, x);
}

/*------------------------------------------------------------------------------
// Name: exp2
//----------------------------------------------------------------------------*/
double exp2(double x) {

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

	return __elibc_exp2(x);
}

#endif
