
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: atan2l
//----------------------------------------------------------------------------*/
long double atan2l(long double x, long double y) {
	return __builtin_atan2l(x, y);
}
