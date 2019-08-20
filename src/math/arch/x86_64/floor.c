
#define __ELIBC_SOURCE
#include <math.h>
#include <fenv.h>

/*------------------------------------------------------------------------------
// Name: floor
//----------------------------------------------------------------------------*/
double floor(double x) {
    double value;
	fesetround(FE_DOWNWARD);
    __asm__ __volatile__ ("frndint" : "=t"(value) : "0"(x));
    return value;
}
