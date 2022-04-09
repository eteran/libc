
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: erfl
//----------------------------------------------------------------------------*/
long double erfl(long double x) {
	return __builtin_erfl(x);
}

#endif
