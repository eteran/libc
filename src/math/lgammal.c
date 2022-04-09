
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: lgammal
//----------------------------------------------------------------------------*/
long double lgammal(long double x) {
	return __builtin_lgammal(x);
}

#endif
