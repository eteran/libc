
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: cosf
//----------------------------------------------------------------------------*/
float cosf(float x) {
	return __builtin_cosf(x);
}
