
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: floorf
//----------------------------------------------------------------------------*/
float floorf(float x) {
	return __builtin_floorf(x);
}
