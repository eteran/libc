
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: lgamma
//----------------------------------------------------------------------------*/
double lgamma(double x) {
	return __builtin_lgamma(x);
}
