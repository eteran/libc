
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: hypotl
//----------------------------------------------------------------------------*/
long double hypotl(long double x, long double y) {
	/* TODO(eteran): check for overflow */
	const long double x2 = x * x;
	const long double y2 = y * y;
	return sqrtl(x2 + y2);
}
