
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: rintf
//----------------------------------------------------------------------------*/
float rintf(float x) { return __builtin_rintf(x); }

#endif
