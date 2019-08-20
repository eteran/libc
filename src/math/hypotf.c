
#define __ELIBC_SOURCE
#include <math.h>
#include <errno.h>

/*------------------------------------------------------------------------------
// Name: hypotf
//----------------------------------------------------------------------------*/
float hypotf(float x, float y) {
	/* TODO(eteran): check for overflow */
	const float x2 = x * x;
	const float y2 = y * y;
	return sqrtf(x2 + y2);
}
