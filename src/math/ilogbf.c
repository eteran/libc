
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: ilogbf
//----------------------------------------------------------------------------*/
int ilogbf(float x) { return __builtin_ilogbf(x); }

#endif
