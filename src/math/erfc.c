
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: erfc
//----------------------------------------------------------------------------*/
double erfc(double x) {
	return __builtin_erfc(x);
}
