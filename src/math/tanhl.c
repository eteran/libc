
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: tanhl
//----------------------------------------------------------------------------*/
long double tanhl(long double x) {
	return __builtin_tanhl(x);
}
