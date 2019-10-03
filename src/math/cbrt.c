
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: cbrt
//----------------------------------------------------------------------------*/
double cbrt(double x) {
	return __builtin_cbrt(x);
}
