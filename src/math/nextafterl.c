
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: nextafterl
//----------------------------------------------------------------------------*/
long double nextafterl(long double x, long double y) {
	return __builtin_nextafterl(x, y);
}
