
#ifndef _C_STRFTIME_H_20051228_
#define _C_STRFTIME_H_20051228_

#include "_time.h"
#include "arch_size_t.h"

_LIBC_BEGIN

size_t strftime(char *s, size_t max, const char *format, const struct tm *tm) _NOEXCEPT
	__attribute__((format(__strftime__, 3, 0)));

_LIBC_END

#endif
