
#ifndef _C_MEMSET_H_20051228_
#define _C_MEMSET_H_20051228_

#include "arch_size_t.h"

_LIBC_BEGIN

_ACCESS((write_only, 1))
void *memset(void *s, int c, size_t n) _NOEXCEPT _NON_NULL(1);

_LIBC_END

#endif
