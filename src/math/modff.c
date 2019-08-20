
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: modff
//----------------------------------------------------------------------------*/
float modff(float x, float *iptr) {
	return __builtin_modff(x, iptr);
}
