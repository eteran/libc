
#define __ELIBC_SOURCE
#include <time.h>
#include <stdint.h>
#include <assert.h>

#define ONE_DAY    86400
#define ONE_HOUR   3600
#define ONE_MINUTE 60

/*------------------------------------------------------------------------------
// Name: __elibc_is_leapyear
//----------------------------------------------------------------------------*/
static int __elibc_is_leapyear(int year) {
	return (((year % 4) == 0) && ((year % 100) != 0)) || ((year % 400) == 0);
}

/*------------------------------------------------------------------------------
// Name: mktime
//----------------------------------------------------------------------------*/
time_t mktime(struct tm *tptr) {

	assert(tptr);
	{
		static const int day_tab[12]      = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		static const int leap_day_tab[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		const int year     = tptr->tm_year + 1900;
		const int *const d = __elibc_is_leapyear(year) ? leap_day_tab : day_tab;
		int y = 1970;

		/* TODO: modify tptr->tm_wday and tptr->tm_yday to make sense if needed */
		/* TODO: for some reason the result is off by about a 1.5 days */
		time_t t = 0;
		int i;

		t += tptr->tm_sec;
		t += tptr->tm_min  * ONE_MINUTE;
		t += tptr->tm_hour * ONE_HOUR;
		t += tptr->tm_mday * ONE_DAY;

		for(i = 0; i < tptr->tm_mon; ++i) {
			t += d[i] * ONE_DAY;
		}

		if(year >= 1970) {
			while(y < year) {
				t += ONE_DAY * (__elibc_is_leapyear(y++) ? 366 : 365);
			}
		} else {
			while(y > year) {
				t -= ONE_DAY * (__elibc_is_leapyear(y--) ? 366 : 365);
			}
		}

		if(tptr->tm_isdst) {
			t -= ONE_HOUR;
		}

		return t;
	}
}
