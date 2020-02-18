
#ifndef _C_SNPRINTF_H_20051228_
#define _C_SNPRINTF_H_20051228_

#include "arch_size_t.h"

_LIBC_BEGIN

int snprintf(char *str, size_t size, const char *format, ...) _NOEXCEPT __attribute__((__format__ (printf, 3, 4)));

_LIBC_END

#endif
