
#ifndef SNPRINTF_20051228_H_
#define SNPRINTF_20051228_H_

#include "arch_size_t.h"

_LIBC_BEGIN

int snprintf(char *str, size_t size, const char *format, ...) _NOEXCEPT __attribute__((__format__ (printf, 3, 4)));

_LIBC_END

#endif
