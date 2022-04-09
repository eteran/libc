
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: ilogbl
//----------------------------------------------------------------------------*/
int ilogbl(long double x) { return __builtin_ilogbl(x); }

#endif
