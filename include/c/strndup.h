
#ifndef _C_STRNDUP_H_20051228_
#define _C_STRNDUP_H_20051228_

#include "arch_size_t.h"

_LIBC_BEGIN

_ACCESS((read_only, 1))
char *strndup(const char *s, size_t n) _NOEXCEPT __attribute__((__malloc__));

_LIBC_END

#endif
