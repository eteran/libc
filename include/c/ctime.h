
#ifndef CTIME_20051228_H_
#define CTIME_20051228_H_

#include "_time.h"

#ifdef __cplusplus
extern "C" {
#endif

char *ctime(const time_t *timer) __ELIBC_NOTHROW;
char *ctime_r(const time_t *timer, char *buf) __ELIBC_NOTHROW;

#ifdef __cplusplus
}
#endif

#endif
