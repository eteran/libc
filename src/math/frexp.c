
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: frexp
//----------------------------------------------------------------------------*/
double frexp(double x, int *exp) { return __builtin_frexp(x, exp); }

#endif
