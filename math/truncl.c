
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: truncl
//----------------------------------------------------------------------------*/
long double truncl(long double x) {
	return __builtin_truncl(x);
}
