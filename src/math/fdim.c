
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: fdim
//----------------------------------------------------------------------------*/
double fdim(double x, double y) {
	return __builtin_fdim(x, y);
}
