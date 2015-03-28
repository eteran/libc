
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: ilogbl
//----------------------------------------------------------------------------*/
long double ilogbl(long double x) {
	return __builtin_ilogbl(x);
}
