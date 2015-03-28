
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: logb
//----------------------------------------------------------------------------*/
double logb(double x) {
	return __builtin_logb(x);
}
