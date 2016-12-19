
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: nanl
//----------------------------------------------------------------------------*/
long double nanl(const char *tagp) {
	return __builtin_nanl(tagp);
}
