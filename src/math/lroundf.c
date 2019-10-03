
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: lroundf
//----------------------------------------------------------------------------*/
long int lroundf(float x) {
	return __builtin_lroundf(x);
}
