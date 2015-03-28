
#define __ELIBC_SOURCE
#include <math.h>
#include <fenv.h>

/*------------------------------------------------------------------------------
// Name: round
//----------------------------------------------------------------------------*/
double round(double x) {
    double value;
	fesetround(FE_TONEAREST);
    __asm__ __volatile__ ("frndint" : "=t"(value) : "0"(x));
    return value;
}
