
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: cbrtf
//----------------------------------------------------------------------------*/
float cbrtf(float x) {
	return __builtin_cbrtf(x);
}
