
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: log1pl
//----------------------------------------------------------------------------*/
long double log1pl(long double x) {
	return __builtin_log1pl(x);
}
