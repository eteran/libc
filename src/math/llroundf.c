
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: llroundf
//----------------------------------------------------------------------------*/
long long int llroundf(float x) {
	return __builtin_llroundf(x);
}
