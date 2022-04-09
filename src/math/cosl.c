
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: cosl
//----------------------------------------------------------------------------*/
long double cosl(long double x) {
	return __builtin_cosl(x);
}

#endif
