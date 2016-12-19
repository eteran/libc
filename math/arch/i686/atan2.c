
#define __ELIBC_SOURCE
#include <math.h>

/*------------------------------------------------------------------------------
// Name: 
//----------------------------------------------------------------------------*/
double atan2(double y, double x) {

	double value;

	if(isnan(x)) {
		return x;
	}

	if(isnan(y)) {
		return y;
	}
	
	/* TODO: is intel special cases, the same as C's? */
	
	__asm__ __volatile__("fpatan" : "=t" (value) : "0" (x), "u" (y) : "st(1)");
	return value;
}
