
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: frexpl
//----------------------------------------------------------------------------*/
long double frexpl(long double x, int *exp) {
	return __builtin_frexpl(x, exp);
}

#endif
