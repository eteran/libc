
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: nan
//----------------------------------------------------------------------------*/
double nan(const char *tagp) {
	return __builtin_nan(tagp);
}

#endif
