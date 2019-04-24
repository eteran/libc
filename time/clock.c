
#define __ELIBC_SOURCE
#include <stdio.h>
#include <time.h>
#include "c/_support.h"

/*------------------------------------------------------------------------------
// Name: clock
//----------------------------------------------------------------------------*/
clock_t clock(void) {

	/* TODO(eteran): this is incorrect, because it is wall time, not time used
	 * by the process which is a big difference getrusage(RUSAGE_SELF, &ru)
	 * would be more appropriate
	 */

	struct timeval tv;
	if(__elibc_sys_gettimeofday(&tv, 0) == -1) {
		return (clock_t)-1;
	}


	/* this assumes that CLOCKS_PER_SEC == 1000000, 
	 * which it is according to POSIX
	 */
	return (clock_t)((tv.tv_sec * CLOCKS_PER_SEC) + tv.tv_usec);
}
