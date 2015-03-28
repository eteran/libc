
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: fmodl
//----------------------------------------------------------------------------*/
long double fmodl(long double x, long double y) {
	return __builtin_fmodl(x, y);
}
