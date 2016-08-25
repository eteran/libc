
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: lroundf
//----------------------------------------------------------------------------*/
long int lroundf(float x) {
	return __builtin_lroundf(x);
}
