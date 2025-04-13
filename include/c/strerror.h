
#ifndef _C_STRERROR_H_20051228_
#define _C_STRERROR_H_20051228_

#include "arch_size_t.h"

_LIBC_BEGIN

_ACCESS((write_only, 2))
int strerror_r(int errnum, char *buf, size_t n) _NOEXCEPT _NON_NULL(2);
char *strerror(int errnum) _NOEXCEPT;

_LIBC_END

#endif
