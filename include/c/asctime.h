
#ifndef ASCTIME_20051228_H_
#define ASCTIME_20051228_H_

#include "arch_size_t.h"
#include "_time.h"

#ifdef __cplusplus
extern "C" {
#endif

char *asctime(const struct tm *timeptr) __ELIBC_NOTHROW;
char *asctime_r(const struct tm *timeptr, char *buf) __ELIBC_NOTHROW;

#ifdef __cplusplus
}
#endif

#endif
