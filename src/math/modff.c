
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: modff
//----------------------------------------------------------------------------*/
float modff(float x, float *iptr) {
	return __builtin_modff(x, iptr);
}
