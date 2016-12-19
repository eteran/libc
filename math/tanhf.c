
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: tanhf
//----------------------------------------------------------------------------*/
float tanhf(float x) {
	return __builtin_tanhf(x);
}
