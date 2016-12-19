
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: nan
//----------------------------------------------------------------------------*/
double nan(const char *tagp) {
	return __builtin_nan(tagp);
}
