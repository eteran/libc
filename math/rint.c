
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: rint
//----------------------------------------------------------------------------*/
double rint(double x) {
	return __builtin_rint(x);
}
