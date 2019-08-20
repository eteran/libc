
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: erfcf
//----------------------------------------------------------------------------*/
float erfcf(float x) {
	return __builtin_erfcf(x);
}
