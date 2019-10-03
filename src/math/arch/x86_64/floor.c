
#define __ELIBC_SOURCE
#include <fenv.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: __elibc_floor
//----------------------------------------------------------------------------*/
double __elibc_floor(double x) {
	double value;
	fesetround(FE_DOWNWARD);
	__asm__ __volatile__("frndint"
						 : "=t"(value)
						 : "0"(x));
	return value;
}

/*------------------------------------------------------------------------------
// Name: floor
//----------------------------------------------------------------------------*/
double floor(double x) {
	return __elibc_floor(x);
}
