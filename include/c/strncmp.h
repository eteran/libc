
#ifndef _C_STRNCMP_H_20051228_
#define _C_STRNCMP_H_20051228_

#include "arch_size_t.h"

_LIBC_BEGIN

_ACCESS((read_only, 1))
_ACCESS((read_only, 2))
_PURE int strncmp(const char *s1, const char *s2, size_t n) _NOEXCEPT;

_LIBC_END

#endif
