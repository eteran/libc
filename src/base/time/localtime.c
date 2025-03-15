
#define _ELIBC_SOURCE
#include <time.h>

/**
 * @brief Convert a time_t value to local time
 *
 * @param timer pointer to a time_t value representing the time to be converted
 * @param result pointer to a struct tm where the result will be stored
 * @return pointer to the struct tm containing the local time representation of the input time
 */
struct tm *localtime_r(const time_t *timer, struct tm *result) {

	/* TODO(eteran): I believe that this function is pretty much the same as
	 * gmtime_r just adjusted for local timezone
	 */

	return gmtime_r(timer, result);
}

/**
 * @brief Convert a time_t value to local time
 *
 * @param timer pointer to a time_t value representing the time to be converted
 * @return pointer to a struct tm containing the local time representation of the input time
 * @note The returned pointer points to a static struct tm object that is reused on subsequent calls to localtime.
 */
struct tm *localtime(const time_t *timer) {
	static _Thread_local struct tm result;
	return localtime_r(timer, &result);
}
