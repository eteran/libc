
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: sinhf
//----------------------------------------------------------------------------*/
float sinhf(float x) {
	return __builtin_sinhf(x);
}
