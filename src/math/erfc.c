
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: erfc
//----------------------------------------------------------------------------*/
double erfc(double x) { return __builtin_erfc(x); }

#endif
