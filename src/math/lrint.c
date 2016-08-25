
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: lrint
//----------------------------------------------------------------------------*/
long int lrint(double x) {
	return __builtin_lrint(x);
}
