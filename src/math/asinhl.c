
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: asinhl
//----------------------------------------------------------------------------*/
long double asinhl(long double x) {
	return __builtin_asinhl(x);
}
