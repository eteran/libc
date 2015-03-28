
#ifndef LOCALTIME_20051228_H_
#define LOCALTIME_20051228_H_

#include "arch_size_t.h"
#include "_time.h"

#ifdef __cplusplus
extern "C" {
#endif

struct tm *localtime(const time_t *timer) __ELIBC_NOTHROW;
struct tm *localtime_r(const time_t *timep, struct tm *result) __ELIBC_NOTHROW;

#ifdef __cplusplus
}
#endif

#endif
