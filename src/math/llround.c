
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: llround
//----------------------------------------------------------------------------*/
long long int llround(double x) {
	return __builtin_llround(x);
}
