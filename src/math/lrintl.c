
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: lrintl
//----------------------------------------------------------------------------*/
long double lrintl(long double x) {
	return __builtin_lrintl(x);
}
