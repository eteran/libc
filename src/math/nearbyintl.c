
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: nearbyintl
//----------------------------------------------------------------------------*/
long double nearbyintl(long double x) {
	return __builtin_nearbyintl(x);
}
