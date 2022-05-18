
#define _ELIBC_SOURCE
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: __elibc_log
//----------------------------------------------------------------------------*/
_ALWAYS_INLINE _INLINE static double __elibc_log(double x) {
	double value;
	__asm__ __volatile__("fldln2; fxch; fyl2x" : "=t"(value) : "0"(x) : "st(1)");
	return value;
}

/*------------------------------------------------------------------------------
// Name: log
//----------------------------------------------------------------------------*/
double log(double x) {
	return __elibc_log(x);
}

#endif
