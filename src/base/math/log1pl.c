
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: log1pl
//----------------------------------------------------------------------------*/
long double log1pl(long double x) {
	return __builtin_log1pl(x);
}

#endif
