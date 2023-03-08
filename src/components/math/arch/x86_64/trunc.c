
#define _ELIBC_SOURCE
#include <fenv.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: __elibc_trunc
//----------------------------------------------------------------------------*/
_ALWAYS_INLINE _INLINE static double __elibc_trunc(double x) {
	double value;
	const int save_round = fesetround(FE_TOWARDZERO);
	__asm__ __volatile__("frndint"
						 : "=t"(value)
						 : "0"(x));
	fesetround(save_round);
	return value;
}

/*------------------------------------------------------------------------------
// Name: trunc
//----------------------------------------------------------------------------*/
double trunc(double x) {
#ifndef __FAST_MATH__
	if (isnan(x)) {
		return x;
	}

	if (x == 0.0 || x == -0.0) {
		return x;
	}

	if (isinf(x)) {
		return x;
	}
#endif

	return __elibc_trunc(x);
}

#endif
