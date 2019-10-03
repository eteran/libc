
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: frexpl
//----------------------------------------------------------------------------*/
long double frexpl(long double x, int *exp) {
	return __builtin_frexpl(x, exp);
}
