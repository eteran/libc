
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: expm1
//----------------------------------------------------------------------------*/
double expm1(double x) {
	return __builtin_expm1(x);
}
