
#ifndef _POSIX_TIME_20140704_H_
#define _POSIX_TIME_20140704_H_

#include "_time.h"

typedef long int suseconds_t;

struct timeval {
	time_t      tv_sec;  /* seconds */
	suseconds_t tv_usec; /* microseconds */
};

struct timezone {
	int  tz_minuteswest; /* minutes W of Greenwich */
	int  tz_dsttime;     /* type of dst correction */
};

#endif
