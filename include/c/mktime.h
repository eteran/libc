
#ifndef MKTIME_20110401_H_
#define MKTIME_20110401_H_

#include "_time.h"

#ifdef __cplusplus
extern "C" {
#endif

time_t mktime(struct tm *tptr) __ELIBC_NOTHROW;

#ifdef __cplusplus
}
#endif

#endif
