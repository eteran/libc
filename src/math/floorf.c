
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: floorf
//----------------------------------------------------------------------------*/
float floorf(float x) {
	return __builtin_floorf(x);
}
