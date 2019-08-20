
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: acosl
//----------------------------------------------------------------------------*/
long double acosl(long double x) {
	return __builtin_acosl(x);
}
