
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: nanl
//----------------------------------------------------------------------------*/
long double nanl(const char *tagp) {
	return __builtin_nanl(tagp);
}
