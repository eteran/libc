
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: coshl
//----------------------------------------------------------------------------*/
long double coshl(long double x) {
	return __builtin_coshl(x);
}
