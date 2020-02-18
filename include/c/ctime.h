
#ifndef _C_CTIME_H_20051228_
#define _C_CTIME_H_20051228_

#include "_time.h"

_LIBC_BEGIN

char *ctime(const time_t *timer) _NOEXCEPT;
char *ctime_r(const time_t *timer, char *buf) _NOEXCEPT;

_LIBC_END

#endif
