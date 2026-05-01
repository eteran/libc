
#define _ELIBC_SOURCE
#include <assert.h>
#include <errno.h>
#include <stdint.h>
#include <time.h>

#define ONE_DAY 86400l

/**
 * @brief Compute the floor division of `a` by `b` for positive `b`.
 *
 * @param a the dividend.
 * @param b the divisor (must be positive).
 * @return floor(a / b).
 * @note C integer division truncates toward zero, which differs from floor
 *       division for negative `a`. This helper corrects that difference.
 */
static int64_t __elibc_idiv(int64_t a, int64_t b) {
	return a / b - (a % b != 0 && a < 0 ? 1 : 0);
}

/**
 * @brief Compute the number of days from the Unix epoch to the start of `year`.
 *
 * @param year the proleptic Gregorian year number.
 * @return the number of days from 1970-01-01 to January 1 of `year`.
 * @note The constants 492, 19, and 4 are the counts of years in [1, 1969]
 *       divisible by 4, 100, and 400 respectively, used to anchor the formula
 *       to the Unix epoch.
 */
static int64_t __elibc_days_to_year(int year) {
	const int64_t y = (int64_t)year - 1;
	return 365LL * (year - 1970) + (__elibc_idiv(y, 4) - 492) - (__elibc_idiv(y, 100) - 19) + (__elibc_idiv(y, 400) - 4);
}

/**
 * @brief Determine the year for a given time_t value.
 *
 * @param t the time_t value to be converted.
 * @param out pointer to a time_t where the seconds since the Unix epoch of
 *            January 1 of the returned year will be stored.
 * @return the proleptic Gregorian year containing `t`.
 */
static int __elibc_get_year(time_t t, time_t *out) {

	int year;
	/* Floor-divide to get the day number (handles negative t correctly). */
	int64_t days = (int64_t)t / ONE_DAY;
	if (t < 0 && (int64_t)t % ONE_DAY != 0) {
		days--;
	}

	/* Initial estimate using the 400-year Gregorian cycle (146097 days). */
	year = (int)(1970 + days * 400 / 146097);

	/* Correct the estimate; converges in at most a few iterations. */
	while (__elibc_days_to_year(year + 1) <= days) {
		year++;
	}

	while (__elibc_days_to_year(year) > days) {
		year--;
	}

	*out = (time_t)(__elibc_days_to_year(year) * ONE_DAY);
	return year;
}

/**
 * @brief Determine if a given year is a leap year.
 *
 * @param year the year to check.
 * @return 1 if the year is a leap year, 0 otherwise.
 * @note A year is a leap year if it is divisible by 4, except for years
 *       divisible by 100, unless it is also divisible by 400.
 */
static int __elibc_is_leapyear(int year) {
	return (((year % 4) == 0) && ((year % 100) != 0)) || ((year % 400) == 0);
}

/**
 * @brief Determine the day of the week for a given date
 *
 * @param year the year of the date
 * @param month the month of the date (0-11)
 * @param day the day of the month (1-31)
 * @note The algorithm used is Zeller's Congruence
 * @return the day of the week (0-6, where 0 is Sunday)
 */
static int __elibc_get_weekday(int year, int month, int day) {

	static const int tab[12] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};

	int r = year;

	assert(month >= 0 && month < 12);
	assert(day > 0 && day <= 31);

	r += (year / 4);
	r -= (year / 100);
	r += (year / 400);
	r += day;
	r += tab[month];
	r -= 1;
	r %= 7;
	return r;
}

/**
 * @brief Get the broken out date from a time_t value
 *
 * @param t the time_t value to be converted
 * @param year the year to be used
 * @param mon  the calculated month (0-11)
 * @param day the calculated day of the month (1-31)
 * @param wday the calculated weekday (0-6, where 0 is Sunday)
 * @return 0 on success, -1 on failure
 */
static int __elibc_get_date(time_t t, int year, int *mon, int *day, int *wday) {
	static const int day_tab[12]      = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	static const int leap_day_tab[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	const int *d                      = __elibc_is_leapyear(year) ? leap_day_tab : day_tab;

	time_t n = 0;
	int i;
	int j;
	for (i = 0; i < 12; ++i) {
		for (j = 1; j <= d[i]; ++j) {
			if (n == t) {
				*day  = j;
				*mon  = i;
				*wday = __elibc_get_weekday(year, i, j);
				return 0;
			}
			n += 1;
		}
	}
	return -1;
}

/**
 * @brief Convert a time_t value to UTC
 *
 * @param timep pointer to a time_t value representing the time to be converted
 * @param result pointer to a struct tm where the result will be stored
 * @return pointer to the struct tm containing the UTC representation of the input time
 */
struct tm *gmtime_r(const time_t *timep, struct tm *result) {
	if (!timep) {
		errno = EINVAL;
		return 0;
	} else {
		time_t year_offset;
		time_t t = *timep;
		int year = __elibc_get_year(t, &year_offset);

		/* this helps deal with negative dates */
		t -= year_offset;

		result->tm_sec = (int)t % 60;
		t /= 60;

		result->tm_min = (int)t % 60;
		t /= 60;

		result->tm_hour = (int)t % 24;
		t /= 24;

		/* at this point, t is a number from 0 to 365 inclusive */
		result->tm_yday = (int)t;

		result->tm_year = year - 1900;

		__elibc_get_date(t, year, &result->tm_mon, &result->tm_mday, &result->tm_wday);

		/* TODO(eteran): get this from the system */
		result->tm_isdst = 0;

		return result;
	}
}

/**
 * @brief Convert a time_t value to UTC
 *
 * @param timep pointer to a time_t value representing the time to be converted
 * @return pointer to a struct tm containing the UTC representation of the input time
 * @note The returned pointer points to a static struct tm object that is reused on subsequent calls to gmtime.
 */
struct tm *gmtime(const time_t *timep) {
	static _Thread_local struct tm result;
	return gmtime_r(timep, &result);
}
