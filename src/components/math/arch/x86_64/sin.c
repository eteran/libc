
#define _ELIBC_SOURCE
#include <errno.h>
#include <fenv.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: __elibc_sin
//----------------------------------------------------------------------------*/
_CONST _ALWAYS_INLINE _INLINE static double __elibc_sin(double x) {
	double value;
	__asm__ __volatile__("fsin"
						 : "=t"(value)
						 : "0"(x));
	return value;
}

/*------------------------------------------------------------------------------
// Name: sin
//----------------------------------------------------------------------------*/
double sin(double x) {
#ifndef __FAST_MATH__
	if (x == 0.0) {
		return x;
	}

	if (isnan(x)) {
		return x;
	}

	if (isinf(x)) {
		errno = EDOM;
		feraiseexcept(FE_INVALID);
		return NAN;
	}
#endif

	return __elibc_sin(x);
}

#endif
