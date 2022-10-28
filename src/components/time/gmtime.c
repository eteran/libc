
#define _ELIBC_SOURCE
#include <stdint.h>
#include <time.h>

#define ONE_DAY 86400

/*------------------------------------------------------------------------------
// Name: __elibc_is_leapyear
//----------------------------------------------------------------------------*/
static int __elibc_is_leapyear(int year) {
	return (((year % 4) == 0) && ((year % 100) != 0)) || ((year % 400) == 0);
}

/*------------------------------------------------------------------------------
// Name: __elibc_get_year
//----------------------------------------------------------------------------*/
static int __elibc_get_year(time_t t, time_t *out) {
	int year = 1970;
	/* 64 bit so we can handle the edge cases near INT_MAX/INT_MIN */
	/* TODO(eteran): handle this better */
	int64_t x = 0;

	while (x < t) {
		x += ONE_DAY * (__elibc_is_leapyear(year) ? 366 : 365);
		year += 1;
	}

	while (x > t) {
		x -= ONE_DAY * (__elibc_is_leapyear(year - 1) ? 366 : 365);
		year -= 1;
	}

	*out = x;

	return year;
}

/*------------------------------------------------------------------------------
// Name: __elibc_get_weekday
//----------------------------------------------------------------------------*/
static int __elibc_get_weekday(int year, int month, int day) {

	static const int tab[12] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};

	int r = year;
	r += (year / 4);
	r -= (year / 100);
	r += (year / 400);
	r += day;
	r += tab[month];
	r -= 1;
	r %= 7;
	return r;
}

/*------------------------------------------------------------------------------
// Name: __elibc_get_date
//----------------------------------------------------------------------------*/
static int __elibc_get_date(time_t t, int year, int *mon, int *day, int *wday) {
	static const int day_tab[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	static const int leap_day_tab[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	const int *d = __elibc_is_leapyear(year) ? leap_day_tab : day_tab;

	time_t n = 0;
	int i;
	int j;
	for (i = 0; i < 12; ++i) {
		for (j = 1; j <= d[i]; ++j) {
			if (n == t) {
				*day = j;
				*mon = i;
				*wday = __elibc_get_weekday(year, i, j);
				return 0;
			}
			n += 1;
		}
	}
	return -1;
}

/*------------------------------------------------------------------------------
// Name: gmtime_r
//----------------------------------------------------------------------------*/
struct tm *gmtime_r(const time_t *timep, struct tm *result) {
	if (!timep) {
		/* TODO(eteran): set errno */
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

/*------------------------------------------------------------------------------
// Name: gmtime
//----------------------------------------------------------------------------*/
struct tm *gmtime(const time_t *timep) {
	static _Thread_local struct tm result;
	return gmtime_r(timep, &result);
}
