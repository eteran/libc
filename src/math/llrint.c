
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: llrint
//----------------------------------------------------------------------------*/
long long int llrint(double x) {
	return __builtin_llrint(x);
}