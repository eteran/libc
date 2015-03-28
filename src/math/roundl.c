
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: roundl
//----------------------------------------------------------------------------*/
long double roundl(long double x) {
	return __builtin_roundl(x);
}
