
#define _ELIBC_SOURCE
#include "c/_support.h"
#include <time.h>

/*------------------------------------------------------------------------------
// Name: time
//----------------------------------------------------------------------------*/
time_t time(time_t *tod) {
	struct timeval tv;

	if (__elibc_sys_gettimeofday(&tv, 0) == 0) {
		if (tod) {
			*tod = tv.tv_sec;
		}

		return tv.tv_sec;
	}

	return (time_t)-1;
}
