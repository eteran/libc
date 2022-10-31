
#define _ELIBC_SOURCE
#include <time.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: difftime
//----------------------------------------------------------------------------*/
double difftime(time_t time1, time_t time0) {
	return (double)(time1 - time0);
}

#endif
