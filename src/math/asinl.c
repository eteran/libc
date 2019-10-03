
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: asinl
//----------------------------------------------------------------------------*/
long double asinl(long double x) {
	return __builtin_asinl(x);
}
