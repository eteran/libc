
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: atanh
//----------------------------------------------------------------------------*/
double atanh(double x) {
	return __builtin_atanh(x);
}
