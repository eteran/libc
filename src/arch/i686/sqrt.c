
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: 
//----------------------------------------------------------------------------*/
double sqrt(double x) {
    double value;

#ifndef __FAST_MATH__
	if(x < -0) {
		errno = EDOM;
		return NAN;
	}

	if(isnan(x)) {
		return x;
	}
	
	if(isinf(x)) {
		return x;
	}
		
	if(x == 0 || x == -0) {
		return x;
	}
#endif
    __asm__ __volatile__ ("fsqrt" : "=t" (value) : "0" (x));
    return value;
}
