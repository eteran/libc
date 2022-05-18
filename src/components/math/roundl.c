
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: roundl
//----------------------------------------------------------------------------*/
long double roundl(long double x) {
	return __builtin_roundl(x);
}

#endif
