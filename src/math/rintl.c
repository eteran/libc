
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: rintl
//----------------------------------------------------------------------------*/
long double rintl(long double x) {
	return __builtin_rintl(x);
}
