
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: nexttowardf
//----------------------------------------------------------------------------*/
float nexttowardf(float x, long double y) {
	return __builtin_nexttowardf(x, y);
}
