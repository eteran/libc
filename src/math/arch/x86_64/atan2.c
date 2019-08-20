
#define __ELIBC_SOURCE
#include <math.h>

/*------------------------------------------------------------------------------
// Name: atan2
//----------------------------------------------------------------------------*/
double atan2(double y, double x) {

	double value;
	
#ifndef __FAST_MATH__
#if 0
	if(isnan(x)) {
		return x;
	}

	if(isnan(y)) {
		return y;
	}
	
	/* TODO(eteran): are intel's special cases, the same as C's? */
#endif
#endif

	__asm__ __volatile__("fpatan" : "=t" (value) : "0" (x), "u" (y) : "st(1)");
	return value;
}
