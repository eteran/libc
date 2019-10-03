
#ifndef ASCTIME_20051228_H_
#define ASCTIME_20051228_H_

#include "arch_size_t.h"
#include "_time.h"

_LIBC_BEGIN

char *asctime(const struct tm *timeptr) _NOEXCEPT;
char *asctime_r(const struct tm *timeptr, char *buf) _NOEXCEPT;

_LIBC_END

#endif
