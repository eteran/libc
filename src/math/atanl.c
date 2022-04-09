
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: atanl
//----------------------------------------------------------------------------*/
long double atanl(long double x) {
	return __builtin_atanl(x);
}

#endif
