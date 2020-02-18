
#ifndef _C_TIME_H_20051228_
#define _C_TIME_H_20051228_

typedef long int clock_t;
typedef long int time_t;

struct tm {
	int tm_sec;   /* seconds after the minute (from 0) */
	int tm_min;   /* minutes after the hour (from 0) */
	int tm_hour;  /* hour of the day (from 0) */
	int tm_mday;  /* day of the month (from 1) */
	int tm_mon;   /* month of the year (from 0) */
	int tm_year;  /* years since 1900 (from 0) */
	int tm_wday;  /* days since Sunday (from 0) */
	int tm_yday;  /* day of the year (from 0) */
	int tm_isdst; /* Daylight Saving Time flag */
};

#endif
