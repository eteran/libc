
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: log1p
//----------------------------------------------------------------------------*/
double log1p(double x) {
	return __builtin_log1p(x);
}
