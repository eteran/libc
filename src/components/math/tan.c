
#define _ELIBC_SOURCE
#include <errno.h>
#include <fenv.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: __elibc_tan
//----------------------------------------------------------------------------*/
_CONST _ALWAYS_INLINE _INLINE static double __elibc_tan(double x) {

	/* TODO(eteran): account for possible overflow */
	const double cos_val = cos(x);
	if (cos_val != 0.0) {
		return sin(x) / cos_val;
	} else {
		errno = EDOM;
		return 0.0;
	}
}

/*------------------------------------------------------------------------------
// Name: tan
//----------------------------------------------------------------------------*/
double tan(double x) {
#ifndef __FAST_MATH__
	if (isnan(x)) {
		errno = EDOM;
		return x;
	}

	if (isinf(x)) {
		errno = EDOM;
		feraiseexcept(FE_INVALID);
		return NAN;
	}
#endif

	return __elibc_tan(x);
}

#endif
