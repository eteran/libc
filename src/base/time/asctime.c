
#define _ELIBC_SOURCE
#include <stdio.h>
#include <time.h>

/**
 * @brief Convert a struct tm to a string representation
 *
 * @param timeptr pointer to a struct tm containing the time to be converted
 * @param buf pointer to a buffer where the string representation will be stored
 * @return char* pointer to the buffer containing the time representation
 * @note buf must be at least 26 bytes big.
 */
char *asctime_r(const struct tm *timeptr, char *buf) {
	if (timeptr) {
		if (timeptr->tm_wday < 7 && timeptr->tm_mon < 12) {

			static const char wday_name[][4] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

			static const char mon_name[][4] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
											   "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

			sprintf(buf, "%.3s %.3s%3d %.2d:%.2d:%.2d %d\n", wday_name[timeptr->tm_wday],
					mon_name[timeptr->tm_mon], timeptr->tm_mday, timeptr->tm_hour, timeptr->tm_min,
					timeptr->tm_sec, 1900 + timeptr->tm_year);

			return buf;
		}
	}

	return 0;
}

/**
 * @brief Convert a struct tm to a string representation
 *
 * @param timeptr pointer to a struct tm containing the time to be converted
 * @return char* pointer to a string containing the time representation
 * @note The returned pointer points to a static buffer that is reused on subsequent calls to asctime.
 */
char *asctime(const struct tm *timeptr) {
	static _Thread_local char result[64];
	return asctime_r(timeptr, result);
}
