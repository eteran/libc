
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: log10l
//----------------------------------------------------------------------------*/
long double log10l(long double x) { return __builtin_log10l(x); }

#endif
