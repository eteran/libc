
#define _ELIBC_SOURCE
#include <fenv.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: __elibc_round
//----------------------------------------------------------------------------*/
_CONST _ALWAYS_INLINE _INLINE static double __elibc_round(double x) {
	double value;
	const int save_round = fesetround(FE_TONEAREST);
	__asm__ __volatile__("frndint" : "=t"(value) : "0"(x));
	fesetround(save_round);
	return value;
}

/*------------------------------------------------------------------------------
// Name: round
//----------------------------------------------------------------------------*/
double round(double x) {
	return __elibc_round(x);
}

#endif
