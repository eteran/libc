
#define __ELIBC_SOURCE
#include <time.h>

#ifdef _HAS_FPU

/*------------------------------------------------------------------------------
// Name: difftime
// TODO(eteran): is this allowed to be a macro?
//----------------------------------------------------------------------------*/
double difftime(time_t time1, time_t time0) { return (double)(time1 - time0); }

#endif
