
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: lgamma
//----------------------------------------------------------------------------*/
double lgamma(double x) {
	return __builtin_lgamma(x);
}
