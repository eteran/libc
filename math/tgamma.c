
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: tgamma
//----------------------------------------------------------------------------*/
double tgamma(double x) {
	return __builtin_tgamma(x);
}
