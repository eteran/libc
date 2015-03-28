
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: hypot
//----------------------------------------------------------------------------*/
double hypot(double x, double y) {
	return __builtin_hypot(x, y);
}
