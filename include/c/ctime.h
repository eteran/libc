
#ifndef CTIME_20051228_H_
#define CTIME_20051228_H_

#include "_time.h"

#ifdef __cplusplus
extern "C" {
#endif

char *ctime(const time_t *timer) _NOEXCEPT;
char *ctime_r(const time_t *timer, char *buf) _NOEXCEPT;

#ifdef __cplusplus
}
#endif

#endif
