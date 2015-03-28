
#define __ELIBC_SOURCE
#include <math.h>

/*------------------------------------------------------------------------------
// Name: 
//----------------------------------------------------------------------------*/
double atan(double x) {
    double value;
    __asm__ __volatile__("fld1; fpatan" : "=t"(value) : "0" (x) : "st(1)");
    return value;
}
