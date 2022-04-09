
#ifndef _C_ASCTIME_H_20051228_
#define _C_ASCTIME_H_20051228_

#include "_time.h"
#include "arch_size_t.h"

_LIBC_BEGIN

char *asctime(const struct tm *timeptr) _NOEXCEPT;
char *asctime_r(const struct tm *timeptr, char *buf) _NOEXCEPT;

_LIBC_END

#endif
