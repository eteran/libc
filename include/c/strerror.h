
#ifndef STRERROR_20051228_H_
#define STRERROR_20051228_H_

#include "arch_size_t.h"

_LIBC_BEGIN

int strerror_r(int errnum, char *buf, size_t n) _NOEXCEPT;
char *strerror(int errnum) _NOEXCEPT;

_LIBC_END

#endif
