

#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: tgammal
//----------------------------------------------------------------------------*/
long double tgammal(long double x) {
	return __builtin_tgammal(x);
}

#endif
