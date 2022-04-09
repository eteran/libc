
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: copysignf
//----------------------------------------------------------------------------*/
float copysignf(float x, float y) { return __builtin_copysignf(x, y); }

#endif
