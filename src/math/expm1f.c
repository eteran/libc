
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: expm1f
//----------------------------------------------------------------------------*/
float expm1f(float x) {
	return expf(x) - 1;
}