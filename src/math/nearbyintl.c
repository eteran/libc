
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: nearbyintl
//----------------------------------------------------------------------------*/
long double nearbyintl(long double x) { return __builtin_nearbyintl(x); }

#endif
