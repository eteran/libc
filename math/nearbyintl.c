
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: nearbyintl
//----------------------------------------------------------------------------*/
long double nearbyintl(long double x) {
	return __builtin_nearbyintl(x);
}
