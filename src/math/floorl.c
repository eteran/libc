
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: floorl
//----------------------------------------------------------------------------*/
long double floorl(long double x) { return __builtin_floorl(x); }

#endif
