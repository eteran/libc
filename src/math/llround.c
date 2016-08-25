
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: llround
//----------------------------------------------------------------------------*/
long long int llround(double x) {
	return __builtin_llround(x);
}
