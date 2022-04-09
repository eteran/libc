
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: __elibc_hypotf
//----------------------------------------------------------------------------*/
static float __elibc_hypotf(float x, float y) {
	/* TODO(eteran): check for overflow */
	const float x2 = x * x;
	const float y2 = y * y;
	return sqrtf(x2 + y2);
}

/*------------------------------------------------------------------------------
// Name: hypotf
//----------------------------------------------------------------------------*/
float hypotf(float x, float y) { return __elibc_hypotf(x, y); }

#endif
