
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: llrintl
//----------------------------------------------------------------------------*/
long long int llrintl(long double x) {
	return __builtin_llrintl(x);
}