
#define __ELIBC_SOURCE
#include <stdio.h>
#include <time.h>

/*------------------------------------------------------------------------------
// Name: asctime_r
//----------------------------------------------------------------------------*/
char *asctime_r(const struct tm *timeptr, char *buf) {
	if (timeptr) {
		if (timeptr->tm_wday < 7 && timeptr->tm_mon < 12) {

			static const char wday_name[][4] = {
				"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

			static const char mon_name[][4] = {
				"Jan", "Feb", "Mar", "Apr", "May", "Jun",
				"Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

			/* NOTE: the API specification says that buf MUST be at least
			 * 26 bytes big. If it is not, UB happens
			 */
			sprintf(buf, "%.3s %.3s%3d %.2d:%.2d:%.2d %d\n",
					wday_name[timeptr->tm_wday],
					mon_name[timeptr->tm_mon],
					timeptr->tm_mday,
					timeptr->tm_hour,
					timeptr->tm_min,
					timeptr->tm_sec,
					1900 + timeptr->tm_year);

			return buf;
		}
	}

	return 0;
}

/*------------------------------------------------------------------------------
// Name: asctime
//----------------------------------------------------------------------------*/
char *asctime(const struct tm *timeptr) {
	static _Thread_local char result[64];
	return asctime_r(timeptr, result);
}
