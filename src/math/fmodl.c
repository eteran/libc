
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: fmodl
//----------------------------------------------------------------------------*/
long double fmodl(long double x, long double y) {
	return __builtin_fmodl(x, y);
}
