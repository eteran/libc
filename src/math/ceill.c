
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: ceill
//----------------------------------------------------------------------------*/
long double ceill(long double x) {
	return __builtin_ceill(x);
}
