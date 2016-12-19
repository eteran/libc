
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: cbrtf
//----------------------------------------------------------------------------*/
float cbrtf(float x) {
	return __builtin_cbrtf(x);
}
