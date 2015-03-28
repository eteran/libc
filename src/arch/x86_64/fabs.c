
#define __ELIBC_SOURCE
#include <math.h>

/*------------------------------------------------------------------------------
// Name: fabs
//----------------------------------------------------------------------------*/
double fabs(double x) {
    double value;
    __asm__ __volatile__ ("fabs" : "=t"(value) : "0"(x));
    return value;
}
