
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: fma
//----------------------------------------------------------------------------*/
double fma(double x, double y, double z) {
	
	// TODO(eteran): account for errors, and rounding mode
	return x * y * z;
}
