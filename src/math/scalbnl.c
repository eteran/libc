
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: scalbnl
//----------------------------------------------------------------------------*/
long double scalbnl(long double x, int exp) {
	return __builtin_scalbnl(x, exp);
}
