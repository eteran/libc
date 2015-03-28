
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: roundf
//----------------------------------------------------------------------------*/
float roundf(float x) {
	return __builtin_roundf(x);
}
