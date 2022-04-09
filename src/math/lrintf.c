
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: lrintf
//----------------------------------------------------------------------------*/
long int lrintf(float x) { return __builtin_lrintf(x); }

#endif
