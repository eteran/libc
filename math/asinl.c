
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: asinl
//----------------------------------------------------------------------------*/
long double asinl(long double x) {
	return __builtin_asinl(x);
}
