
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: sinl
//----------------------------------------------------------------------------*/
long double sinl(long double x) { return __builtin_sinl(x); }

#endif
