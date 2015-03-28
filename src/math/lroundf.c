
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: lroundf
//----------------------------------------------------------------------------*/
float lroundf(float x) {
	return __builtin_lroundf(x);
}
