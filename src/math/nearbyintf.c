
#define __ELIBC_SOURCE
#include <errno.h>
#include <math.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: nearbyintf
//----------------------------------------------------------------------------*/
float nearbyintf(float x) { return __builtin_nearbyintf(x); }

#endif
