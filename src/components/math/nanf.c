
#define _ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: nanf
//----------------------------------------------------------------------------*/
float nanf(const char *tagp) {
	return __builtin_nanf(tagp);
}

#endif
