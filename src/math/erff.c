
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: erff
//----------------------------------------------------------------------------*/
float erff(float x) { return __builtin_erff(x); }

#endif
