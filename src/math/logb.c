
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: logb
//----------------------------------------------------------------------------*/
double logb(double x) {
	return __builtin_logb(x);
}
