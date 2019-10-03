
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: atan2l
//----------------------------------------------------------------------------*/
long double atan2l(long double x, long double y) {
	return __builtin_atan2l(x, y);
}
