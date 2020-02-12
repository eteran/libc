
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: nextafterl
//----------------------------------------------------------------------------*/
long double nextafterl(long double x, long double y) {
	return __builtin_nextafterl(x, y);
}

#endif
