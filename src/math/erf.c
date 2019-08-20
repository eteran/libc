
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: erf
//----------------------------------------------------------------------------*/
double erf(double x) {
	return __builtin_erf(x);
}
