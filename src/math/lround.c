
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: lround
//----------------------------------------------------------------------------*/
long int lround(double x) { return __builtin_lround(x); }

#endif
