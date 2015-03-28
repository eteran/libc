
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: tanl
//----------------------------------------------------------------------------*/
long double tanl(long double x) {
	return __builtin_tanl(x);
}
