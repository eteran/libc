
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: ceill
//----------------------------------------------------------------------------*/
long double ceill(long double x) {
	return __builtin_ceill(x);
}

#endif
