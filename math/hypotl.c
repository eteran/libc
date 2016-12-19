
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: hypotl
//----------------------------------------------------------------------------*/
long double hypotl(long double x, long double y) {
	return __builtin_hypotl(x, y);
}
