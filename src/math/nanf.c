
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: nanf
//----------------------------------------------------------------------------*/
float nanf(const char *tagp) {
	return __builtin_nanf(tagp);
}
