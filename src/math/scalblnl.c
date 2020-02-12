
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: scalblnl
//----------------------------------------------------------------------------*/
long double scalblnl(long double x, long int exp) {
	return __builtin_scalblnl(x, exp);
}

#endif
