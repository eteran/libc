
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: nexttoward
//----------------------------------------------------------------------------*/
double nexttoward(double x, long double y) {
	return __builtin_nexttoward(x, y);
}

#endif
