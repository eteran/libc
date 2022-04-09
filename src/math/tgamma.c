
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: tgamma
//----------------------------------------------------------------------------*/
double tgamma(double x) { return __builtin_tgamma(x); }

#endif
