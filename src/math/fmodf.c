
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: fmodf
//----------------------------------------------------------------------------*/
float fmodf(float x, float y) {
	return __builtin_fmodf(x, y);
}
