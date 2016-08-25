
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: acoshl
//----------------------------------------------------------------------------*/
long double acoshl(long double x) {
	return __builtin_acoshl(x);
}
