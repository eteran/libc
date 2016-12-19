
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: remainderl
//----------------------------------------------------------------------------*/
long double remainderl(long double x, long double y) {
	return __builtin_remainderl(x, y);
}
