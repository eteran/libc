
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: nan
//----------------------------------------------------------------------------*/
double nan(const char *tagp) {
	return __builtin_nan(tagp);
}
