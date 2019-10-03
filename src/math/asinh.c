
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: asinh
//----------------------------------------------------------------------------*/
double asinh(double x) {
	return __builtin_asinh(x);
}
