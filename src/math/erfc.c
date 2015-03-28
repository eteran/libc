
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: erfc
//----------------------------------------------------------------------------*/
double erfc(double x) {
	return __builtin_erfc(x);
}
