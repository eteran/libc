
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: cbrtf
//----------------------------------------------------------------------------*/
float cbrtf(float x) { return __builtin_cbrtf(x); }

#endif
