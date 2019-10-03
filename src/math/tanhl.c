
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: tanhl
//----------------------------------------------------------------------------*/
long double tanhl(long double x) {
	return __builtin_tanhl(x);
}
