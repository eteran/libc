
#define __ELIBC_SOURCE
#include <math.h>

/*------------------------------------------------------------------------------
// Name: __elibc_atan2
//----------------------------------------------------------------------------*/
static double __elibc_atan2(double y, double x) {
	double value;
	__asm__ __volatile__("fpatan"
						 : "=t"(value)
						 : "0"(x), "u"(y)
						 : "st(1)");
	return value;
}

/*------------------------------------------------------------------------------
// Name: atan2
//----------------------------------------------------------------------------*/
double atan2(double y, double x) {

#ifndef __FAST_MATH__
	if (isnan(x)) {
		return x;
	}

	if (isnan(y)) {
		return y;
	}
#endif

	return __elibc_atan2(y, x);
}
