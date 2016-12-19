
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: fmin
//----------------------------------------------------------------------------*/
double fmin(double x, double y) {
	return __builtin_fmin(x, y);
}
