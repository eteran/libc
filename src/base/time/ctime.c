
#define _ELIBC_SOURCE
#include <time.h>

/**
 * @brief Convert a time_t value to a string representation
 *
 * @param timer pointer to a time_t value representing the time to be converted
 * @param buf pointer to a buffer where the string representation will be stored
 * @return char* pointer to the buffer containing the time representation
 */
char *ctime_r(const time_t *timer, char *buf) {
	return asctime_r(localtime(timer), buf);
}

/**
 * @brief Convert a time_t value to a string representation
 *
 * @param timer pointer to a time_t value representing the time to be converted
 * @return char* pointer to a string containing the time representation
 * @note The returned pointer points to a static buffer that is reused on subsequent calls to ctime.
 */
char *ctime(const time_t *timer) {
	static _Thread_local char buf[64];
	return ctime_r(timer, buf);
}
