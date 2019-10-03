
#define __ELIBC_SOURCE
#include <fenv.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: __elibc_ceil
//----------------------------------------------------------------------------*/
double __elibc_ceil(double x) {
	double value;
	fesetround(FE_UPWARD);
	__asm__ __volatile__("frndint"
						 : "=t"(value)
						 : "0"(x));
	return value;
}

/*------------------------------------------------------------------------------
// Name: ceil
//----------------------------------------------------------------------------*/
double ceil(double x) {
	return __elibc_ceil(x);
}
