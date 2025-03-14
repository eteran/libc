
#define _ELIBC_SOURCE
#include <assert.h>
#include <stdint.h>
#include <time.h>

#define ONE_DAY    86400l
#define ONE_HOUR   3600l
#define ONE_MINUTE 60l

/**
 * @brief Determine if a given year is a leap year
 *
 * @param year the year to check
 * @return int 1 if the year is a leap year, 0 otherwise
 * @note A year is a leap year if it is divisible by 4, except for years divisible by 100
 *       unless the year is also divisible by 400.
 */
static int __elibc_is_leapyear(int year) {
	return (((year % 4) == 0) && ((year % 100) != 0)) || ((year % 400) == 0);
}

/**
 * @brief Convert broken down time to time_t
 *
 * @param tptr pointer to a struct tm containing the broken down time to be converted
 * @return time_t the time in seconds since the epoch (00:00:00 UTC, January 1, 1970)
 */
time_t mktime(struct tm *tptr) {

	assert(tptr);
	{
		static const int day_tab[12]      = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		static const int leap_day_tab[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		const int year                    = tptr->tm_year + 1900;
		const int *const d                = __elibc_is_leapyear(year) ? leap_day_tab : day_tab;
		int y                             = 1970;

		/* TODO(eteran): modify tptr->tm_wday and tptr->tm_yday to make sense if
		 * needed */
		/* TODO(eteran): for some reason the result is off by about a 1.5 days */
		time_t t = 0;
		int i;

		t += tptr->tm_sec;
		t += tptr->tm_min * ONE_MINUTE;
		t += tptr->tm_hour * ONE_HOUR;
		t += tptr->tm_mday * ONE_DAY;

		for (i = 0; i < tptr->tm_mon; ++i) {
			t += d[i] * ONE_DAY;
		}

		if (year >= 1970) {
			while (y < year) {
				t += ONE_DAY * (__elibc_is_leapyear(y++) ? 366 : 365);
			}
		} else {
			while (y > year) {
				t -= ONE_DAY * (__elibc_is_leapyear(y--) ? 366 : 365);
			}
		}

		if (tptr->tm_isdst) {
			t -= ONE_HOUR;
		}

		return t;
	}
}
