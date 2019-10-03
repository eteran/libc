
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: acoshl
//----------------------------------------------------------------------------*/
long double acoshl(long double x) {
	return __builtin_acoshl(x);
}
