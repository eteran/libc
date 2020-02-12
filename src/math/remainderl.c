
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: remainderl
//----------------------------------------------------------------------------*/
long double remainderl(long double x, long double y) {
	return __builtin_remainderl(x, y);
}

#endif
