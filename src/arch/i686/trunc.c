
#define __ELIBC_SOURCE
#include <math.h>
#include <fenv.h>

/*------------------------------------------------------------------------------
// Name: 
//----------------------------------------------------------------------------*/
double trunc(double x) {
    double value;
	fesetround(FE_TOWARDZERO);
    __asm__ __volatile__ ("frndint" : "=t"(value) : "0"(x));
    return value;
}
