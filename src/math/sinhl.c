
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: sinhl
//----------------------------------------------------------------------------*/
long double sinhl(long double x) { return __builtin_sinhl(x); }

#endif
