
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: nanl
//----------------------------------------------------------------------------*/
long double nanl(const char *tagp) {
	return __builtin_nanl(tagp);
}

#endif
