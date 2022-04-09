
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: atan2l
//----------------------------------------------------------------------------*/
long double atan2l(long double x, long double y) { return __builtin_atan2l(x, y); }

#endif
