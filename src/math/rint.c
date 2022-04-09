
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: rint
//----------------------------------------------------------------------------*/
double rint(double x) { return __builtin_rint(x); }

#endif
