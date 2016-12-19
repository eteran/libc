
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: fmax
//----------------------------------------------------------------------------*/
double fmax(double x, double y) {
	return __builtin_fmax(x, y);
}
