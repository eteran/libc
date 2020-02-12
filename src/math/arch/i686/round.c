
#define __ELIBC_SOURCE
#include <fenv.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: __elibc_round
//----------------------------------------------------------------------------*/
static double __elibc_round(double x) {
	double value;
	fesetround(FE_TONEAREST);
	__asm__ __volatile__("frndint"
						 : "=t"(value)
						 : "0"(x));
	return value;
}

/*------------------------------------------------------------------------------
// Name: round
//----------------------------------------------------------------------------*/
double round(double x) {
	return __elibc_round(x);
}

#endif
