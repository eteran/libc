
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: logbl
//----------------------------------------------------------------------------*/
long double logbl(long double x) {
	return __builtin_logbl(x);
}
