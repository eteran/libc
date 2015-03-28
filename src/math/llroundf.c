
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: llroundf
//----------------------------------------------------------------------------*/
float llroundf(float x) {
	return __builtin_llroundf(x);
}
