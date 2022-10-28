
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: modfl
//----------------------------------------------------------------------------*/
long double modfl(long double arg, long double *iptr) {
	return __builtin_modfl(arg, iptr);
}

#endif
