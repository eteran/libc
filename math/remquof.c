
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: remquof
//----------------------------------------------------------------------------*/
float remquof(float x, float y, int *quo) {
	return __builtin_remquof(x, y, quo);
}
