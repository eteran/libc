
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: nearbyint
//----------------------------------------------------------------------------*/
double nearbyint(double x) {
	return __builtin_nearbyint(x);
}
