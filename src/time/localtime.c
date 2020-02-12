
#define __ELIBC_SOURCE
#include <time.h>

/*------------------------------------------------------------------------------
// Name: localtime_r
//----------------------------------------------------------------------------*/
struct tm *localtime_r(const time_t *timer, struct tm *result) {

	/* TODO(eteran): I beleive that this function is pretty much the same as gmtime_r
	 * just adjusted for local timezone
	 */

	return gmtime_r(timer, result);
}

/*------------------------------------------------------------------------------
// Name: localtime
//----------------------------------------------------------------------------*/
struct tm *localtime(const time_t *timer) {
	static _Thread_local struct tm result;
	return localtime_r(timer, &result);
}
