
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: frexpl
//----------------------------------------------------------------------------*/
long double frexpl(long double x, int *exp) {
	return __builtin_frexpl(x, exp);
}
