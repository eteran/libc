
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: truncf
//----------------------------------------------------------------------------*/
float truncf(float x) {
	return __builtin_truncf(x);
}
