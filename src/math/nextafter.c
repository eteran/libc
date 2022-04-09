
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: nextafter
//----------------------------------------------------------------------------*/
double nextafter(double x, double y) {
	return __builtin_nextafter(x, y);
}

#endif
