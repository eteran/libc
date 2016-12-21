
#define __ELIBC_SOURCE
#include <time.h>

#if !defined(__x86_64__) || defined(__SSE__)
/*------------------------------------------------------------------------------
// Name: difftime
// TODO: is this allowed to be a macro?
//----------------------------------------------------------------------------*/
double difftime(time_t time1, time_t time0) {
	return (double)(time1 - time0);
}
#endif
