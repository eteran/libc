
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: nexttowardl
//----------------------------------------------------------------------------*/
long double nexttowardl(long double x, long double y) {
	return __builtin_nexttowardl(x, y);
}
