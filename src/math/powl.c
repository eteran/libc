
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: powl
//----------------------------------------------------------------------------*/
long double powl(long double x, long double y) { return __builtin_powl(x, y); }

#endif
