
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: sinhf
//----------------------------------------------------------------------------*/
float sinhf(float x) {
	return __builtin_sinhf(x);
}
