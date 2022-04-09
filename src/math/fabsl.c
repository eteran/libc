
#define __ELIBC_SOURCE
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: __elibc_fabsl
//----------------------------------------------------------------------------*/
static long double __elibc_fabsl(long double x) { return x > 0 ? x : -x; }

/*------------------------------------------------------------------------------
// Name: fabsl
//----------------------------------------------------------------------------*/
long double fabsl(long double x) { return __elibc_fabsl(x); }

#endif
