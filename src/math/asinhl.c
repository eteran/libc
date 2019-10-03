
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: asinhl
//----------------------------------------------------------------------------*/
long double asinhl(long double x) {
	return __builtin_asinhl(x);
}
