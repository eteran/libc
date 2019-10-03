
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: copysignl
//----------------------------------------------------------------------------*/
long double copysignl(long double x, long double y) {
	return __builtin_copysignl(x, y);
}
