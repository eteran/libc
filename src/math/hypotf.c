
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: hypotf
//----------------------------------------------------------------------------*/
float hypotf(float x, float y) {
	return __builtin_hypotf(x, y);
}
