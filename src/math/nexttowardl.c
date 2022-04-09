
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: nexttowardl
//----------------------------------------------------------------------------*/
long double nexttowardl(long double x, long double y) {
	return __builtin_nexttowardl(x, y);
}

#endif
