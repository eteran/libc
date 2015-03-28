
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: nextafterl
//----------------------------------------------------------------------------*/
long double nextafterl(long double x, long double y) {
	return __builtin_nextafterl(x, y);
}
