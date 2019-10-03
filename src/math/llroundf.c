
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: llroundf
//----------------------------------------------------------------------------*/
long long int llroundf(float x) {
	return __builtin_llroundf(x);
}
