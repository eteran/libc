
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: nearbyint
//----------------------------------------------------------------------------*/
double nearbyint(double x) {
	return __builtin_nearbyint(x);
}
