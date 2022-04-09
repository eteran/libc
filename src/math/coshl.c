
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: coshl
//----------------------------------------------------------------------------*/
long double coshl(long double x) { return __builtin_coshl(x); }

#endif
