
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: llrint
//----------------------------------------------------------------------------*/
long long int llrint(double x) {
	return __builtin_llrint(x);
}
