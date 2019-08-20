
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: coshl
//----------------------------------------------------------------------------*/
long double coshl(long double x) {
	return __builtin_coshl(x);
}
