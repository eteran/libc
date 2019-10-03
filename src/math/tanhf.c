
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: tanhf
//----------------------------------------------------------------------------*/
float tanhf(float x) {
	return __builtin_tanhf(x);
}
