
#define __ELIBC_SOURCE
#include <math.h>

/*------------------------------------------------------------------------------
// Name: __elibc_fmod
//----------------------------------------------------------------------------*/
double __elibc_fmod(double x, double y) {
	double value;
	__asm __volatile__(
		"1: fprem    \n"
		"fnstsw %%ax \n"
		"sahf        \n"
		"jp 1b       \n"
		: "=t"(value)
		: "0"(x), "u"(y)
		: "ax", "cc");
	return value;
}

/*------------------------------------------------------------------------------
// Name: fmod
//----------------------------------------------------------------------------*/
double fmod(double x, double y) {
	return __elibc_fmod(x, y);
}
