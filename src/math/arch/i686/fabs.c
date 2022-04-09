
#define __ELIBC_SOURCE
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: __elibc_fabs
//----------------------------------------------------------------------------*/
static double __elibc_fabs(double x) {
	double value;
	__asm__ __volatile__("fabs" : "=t"(value) : "0"(x));
	return value;
}

/*------------------------------------------------------------------------------
// Name: fabs
//----------------------------------------------------------------------------*/
double fabs(double x) {
	return __elibc_fabs(x);
}

#endif
