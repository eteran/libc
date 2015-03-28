
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: nexttowardf
//----------------------------------------------------------------------------*/
float nexttowardf(float x, float y) {
	return __builtin_nexttowardf(x, y);
}
