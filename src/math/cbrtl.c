
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: cbrtl
//----------------------------------------------------------------------------*/
double cbrtl(double x) {
	return __builtin_cbrtl(x);
}
