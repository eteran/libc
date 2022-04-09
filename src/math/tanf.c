
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: tanf
//----------------------------------------------------------------------------*/
float tanf(float x) { return __builtin_tanf(x); }

#endif
