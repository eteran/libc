
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: nanf
//----------------------------------------------------------------------------*/
float nanf(const char *tagp) {
	return __builtin_nanf(tagp);
}
