
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: logbl
//----------------------------------------------------------------------------*/
long double logbl(long double x) {
	return __builtin_logbl(x);
}
