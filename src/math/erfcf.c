
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: erfcf
//----------------------------------------------------------------------------*/
float erfcf(float x) {
	return __builtin_erfcf(x);
}
