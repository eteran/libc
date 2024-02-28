
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: fmodl
//----------------------------------------------------------------------------*/
long double fmodl(long double x, long double y) {
	return __builtin_fmodl(x, y);
}

#endif
