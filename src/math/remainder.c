
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: remainder
//----------------------------------------------------------------------------*/
double remainder(double x, double y) {
	return __builtin_remainder(x, y);
}
