
#define __ELIBC_SOURCE
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: __elibc_atan
//----------------------------------------------------------------------------*/
static double __elibc_atan(double x) {
	double value;
	__asm__ __volatile__("fld1; fpatan" : "=t"(value) : "0"(x) : "st(1)");
	return value;
}

/*------------------------------------------------------------------------------
// Name: atan
//----------------------------------------------------------------------------*/
double atan(double x) {
	return __elibc_atan(x);
}

#endif
