
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: modfl
//----------------------------------------------------------------------------*/
long double modfl(long double x, long double *iptr) {
	return __builtin_modfl(x, iptr);
}

#endif
