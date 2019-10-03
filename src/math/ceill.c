
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: ceill
//----------------------------------------------------------------------------*/
long double ceill(long double x) {
	return __builtin_ceill(x);
}
