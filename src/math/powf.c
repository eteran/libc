
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: powf
//----------------------------------------------------------------------------*/
float powf(float x, float y) {
	return __builtin_powf(x, y);
}
