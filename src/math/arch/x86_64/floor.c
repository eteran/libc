
#define __ELIBC_SOURCE
#include <fenv.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: __elibc_floor
//----------------------------------------------------------------------------*/
static double __elibc_floor(double x) {
	double value;
	fesetround(FE_DOWNWARD);
	__asm__ __volatile__("frndint" : "=t"(value) : "0"(x));
	return value;
}

/*------------------------------------------------------------------------------
// Name: floor
//----------------------------------------------------------------------------*/
double floor(double x) {
	return __elibc_floor(x);
}

#endif
