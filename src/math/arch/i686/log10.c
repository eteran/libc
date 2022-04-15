
#define _ELIBC_SOURCE
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: __elibc_log10
//----------------------------------------------------------------------------*/
_ENSURE_INLINE static double __elibc_log10(double x) {
	double value;
	__asm__ __volatile__("fldlg2; fxch; fyl2x" : "=t"(value) : "0"(x) : "st(1)");
	return value;
}

/*------------------------------------------------------------------------------
// Name: log10
//----------------------------------------------------------------------------*/
double log10(double x) {
	return __elibc_log10(x);
}

#endif
