
#define __ELIBC_SOURCE
#include <math.h>
#include <fenv.h>

/*------------------------------------------------------------------------------
// Name: 
//----------------------------------------------------------------------------*/
double ceil(double x) {
    double value;
	fesetround(FE_UPWARD);
    __asm__ __volatile__ ("frndint" : "=t"(value) : "0"(x));
    return value;
}
