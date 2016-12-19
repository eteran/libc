
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: ldexpl
//----------------------------------------------------------------------------*/
long double ldexpl(long double x, int exp) {
	return __builtin_ldexpl(x, exp);
}
