
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: logf
//----------------------------------------------------------------------------*/
float logf(float x) { return __builtin_logf(x); }

#endif
