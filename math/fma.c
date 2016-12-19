
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: fma
//----------------------------------------------------------------------------*/
double fma(double x, double y, double z) {
	return __builtin_fma(x, y, z);
}
