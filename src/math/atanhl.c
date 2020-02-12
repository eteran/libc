
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: atanhl
//----------------------------------------------------------------------------*/
long double atanhl(long double x) {
	return __builtin_atanhl(x);
}

#endif
