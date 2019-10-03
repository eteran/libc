
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: llrintl
//----------------------------------------------------------------------------*/
long long int llrintl(long double x) {
	return __builtin_llrintl(x);
}
