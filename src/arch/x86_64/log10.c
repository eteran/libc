
#define __ELIBC_SOURCE
#include <math.h>

/*------------------------------------------------------------------------------
// Name: log10
//----------------------------------------------------------------------------*/
double log10(double x) {
	double value;
	__asm__ __volatile__("fldlg2; fxch; fyl2x" : "=t"(value) : "0"(x) : "st(1)");
	return value;
}
