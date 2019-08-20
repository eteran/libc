
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: lrintf
//----------------------------------------------------------------------------*/
long int lrintf(float x) {
	return __builtin_lrintf(x);
}
