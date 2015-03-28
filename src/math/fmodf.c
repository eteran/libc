
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: fmodf
//----------------------------------------------------------------------------*/
float fmodf(float x, float y) {
	return __builtin_fmodf(x, y);
}
