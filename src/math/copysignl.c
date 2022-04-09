
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: copysignl
//----------------------------------------------------------------------------*/
long double copysignl(long double x, long double y) {
	return __builtin_copysignl(x, y);
}

#endif
