
#define __ELIBC_SOURCE
#include <time.h>

/*------------------------------------------------------------------------------
// Name: ctime_r
//----------------------------------------------------------------------------*/
char *ctime_r(const time_t *timer, char *buf) {
	return asctime_r(localtime(timer), buf);
}

/*------------------------------------------------------------------------------
// Name: ctime
//----------------------------------------------------------------------------*/
char *ctime(const time_t *timer) {
	_Thread_local static char buf[64];
	return ctime_r(timer, buf);
}
