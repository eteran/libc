
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: hypotl
//----------------------------------------------------------------------------*/
static long double __elibc_hypotl(long double x, long double y) {
	/* TODO(eteran): check for overflow */
	const long double x2 = x * x;
	const long double y2 = y * y;
	return sqrtl(x2 + y2);
}

/*------------------------------------------------------------------------------
// Name: hypotl
//----------------------------------------------------------------------------*/
long double hypotl(long double x, long double y) {
	return __elibc_hypotl(x, y);
}
