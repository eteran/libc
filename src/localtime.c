
#define __ELIBC_SOURCE
#include <time.h>

/*------------------------------------------------------------------------------
// Name: localtime_r
//----------------------------------------------------------------------------*/
struct tm *localtime_r(const time_t *timer, struct tm *result) {

	(void)timer;
	(void)result;

	/* TODO: I beleive that this function is pretty much the same as gmtime_r
	 * just adjusted for local timezone
	 */

	return result;
}

/*------------------------------------------------------------------------------
// Name: localtime
//----------------------------------------------------------------------------*/
struct tm *localtime(const time_t *timer) {
	_Thread_local static struct tm result;
	return localtime_r(timer, &result);
}

