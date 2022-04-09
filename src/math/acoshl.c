
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: acoshl
//----------------------------------------------------------------------------*/
long double acoshl(long double x) { return __builtin_acoshl(x); }

#endif
