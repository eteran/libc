
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: ilogbl
//----------------------------------------------------------------------------*/
int ilogbl(long double x) {
	return __builtin_ilogbl(x);
}
