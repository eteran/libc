
#define __ELIBC_SOURCE
#include <math.h>

/*------------------------------------------------------------------------------
// Name: 
//----------------------------------------------------------------------------*/
double log(double x) {
	double value;
	__asm__ __volatile__ ("fldln2; fxch; fyl2x" : "=t"(value) : "0"(x) : "st(1)");
	return value;
}
