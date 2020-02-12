
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: scalbnf
//----------------------------------------------------------------------------*/
float scalbnf(float x, int exp) {
	return __builtin_scalbnf(x, exp);
}

#endif
