
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: fminf
//----------------------------------------------------------------------------*/
float fminf(float x, float y) {
	return __builtin_fminf(x, y);
}
