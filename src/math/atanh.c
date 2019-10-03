
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: atanh
//----------------------------------------------------------------------------*/
double atanh(double x) {
	return __builtin_atanh(x);
}
