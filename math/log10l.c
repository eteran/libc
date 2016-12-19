
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: log10l
//----------------------------------------------------------------------------*/
long double log10l(long double x) {
	return __builtin_log10l(x);
}
