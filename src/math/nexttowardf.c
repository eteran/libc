
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

/*------------------------------------------------------------------------------
// Name: nexttowardf
//----------------------------------------------------------------------------*/
float nexttowardf(float x, long double y) {
	return __builtin_nexttowardf(x, y);
}
