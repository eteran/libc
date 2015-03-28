
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: asinh
//----------------------------------------------------------------------------*/
double asinh(double x) {
	return __builtin_asinh(x);
}
