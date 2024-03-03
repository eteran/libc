
#ifndef _C_MEMCMP_H_20051228_
#define _C_MEMCMP_H_20051228_

#include "arch_size_t.h"

_LIBC_BEGIN

_ACCESS((read_only, 1))
_ACCESS((read_only, 2))
_PURE int memcmp(const void *s1, const void *s2, size_t n) _NOEXCEPT;

_LIBC_END

#endif
