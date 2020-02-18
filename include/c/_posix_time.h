
#ifndef _C_POSIX_TIME_H_20140704_
#define _C_POSIX_TIME_H_20140704_

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
