
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: llrintl
//----------------------------------------------------------------------------*/
long double llrintl(long double x) {
	return __builtin_llrintl(x);
}
