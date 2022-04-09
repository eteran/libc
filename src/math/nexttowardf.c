
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: nexttowardf
//----------------------------------------------------------------------------*/
float nexttowardf(float x, long double y) { return __builtin_nexttowardf(x, y); }

#endif
