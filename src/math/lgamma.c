
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: lgamma
//----------------------------------------------------------------------------*/
double lgamma(double x) { return __builtin_lgamma(x); }

#endif
