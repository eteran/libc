
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: remquol
//----------------------------------------------------------------------------*/
long double remquol(long double x, long double y, int *quo) {
	return __builtin_remquol(x, y, quo);
}
