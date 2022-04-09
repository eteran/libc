
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: scalblnf
//----------------------------------------------------------------------------*/
float scalblnf(float x, long int exp) { return __builtin_scalblnf(x, exp); }

#endif
