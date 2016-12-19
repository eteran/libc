
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
	/* TODO: should we use asctime_r here so this doesn't
	 * share the internal buffer with asctime?
	 */
	return asctime(localtime(timer));
}
