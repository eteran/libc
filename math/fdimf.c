
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: fdimf
//----------------------------------------------------------------------------*/
float fdimf(float x, float y) {
	return __builtin_fdimf(x, y);
}
