
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: ilogbl
//----------------------------------------------------------------------------*/
int ilogbl(long double x) {
	return __builtin_ilogbl(x);
}
