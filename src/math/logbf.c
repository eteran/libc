
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: logbf
//----------------------------------------------------------------------------*/
float logbf(float x) { return __builtin_logbf(x); }

#endif
