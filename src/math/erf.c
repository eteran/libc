
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: erf
//----------------------------------------------------------------------------*/
double erf(double x) {
	return __builtin_erf(x);
}
