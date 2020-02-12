
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: roundl
//----------------------------------------------------------------------------*/
long double roundl(long double x) {
	return __builtin_roundl(x);
}

#endif
