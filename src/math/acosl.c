
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: acosl
//----------------------------------------------------------------------------*/
long double acosl(long double x) {
	return __builtin_acosl(x);
}
