
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: cbrt
//----------------------------------------------------------------------------*/
double cbrt(double x) {
	return __builtin_cbrt(x);
}
