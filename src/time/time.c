
#define __ELIBC_SOURCE
#include <time.h>
#include "c/_support.h"

/*------------------------------------------------------------------------------
// Name: time
//----------------------------------------------------------------------------*/
time_t time(time_t *tod) {
	struct timeval tv;

	time_t ret = (time_t)-1;

	if(__elibc_sys_gettimeofday(&tv, 0) == 0) {
		if(tod) {
			*tod = tv.tv_sec;
		}

		ret = tv.tv_sec;
	}

	return ret;
}
