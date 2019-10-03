
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: tgamma
//----------------------------------------------------------------------------*/
double tgamma(double x) {
	return __builtin_tgamma(x);
}
