
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: asinhl
//----------------------------------------------------------------------------*/
long double asinhl(long double x) {
	return __builtin_asinhl(x);
}

#endif
