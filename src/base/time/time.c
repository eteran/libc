
#define _ELIBC_SOURCE
#include "c/_support.h"
#include <time.h>

/**
 * @brief Get the current calendar time
 *
 * @param tod pointer to a time_t object where the current calendar time
 * will be stored. If this parameter is NULL, the function does not store
 * the current calendar time, but the function still returns the current
 * calendar time.
 * @return the current calendar time as a value of type time_t
 * @note The value returned by this function is the number of seconds
 * elapsed since 00:00:00 UTC, January 1, 1970, not counting leap seconds.
 * The time is expressed in Coordinated Universal Time (UTC), which is
 * the same as Greenwich Mean Time (GMT).
 */
time_t time(time_t *tod) {
	return __elibc_time(tod);
}
