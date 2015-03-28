
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: exp2l
//----------------------------------------------------------------------------*/
long double exp2l(long double x) {
	return __builtin_exp2l(x);
}
