
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: floorf
//----------------------------------------------------------------------------*/
float floorf(float x) { return __builtin_floorf(x); }

#endif
