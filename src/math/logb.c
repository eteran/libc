
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: logb
//----------------------------------------------------------------------------*/
double logb(double x) { return __builtin_logb(x); }

#endif
