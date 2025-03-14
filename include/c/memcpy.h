
#ifndef _C_MEMCPY_H_20051228_
#define _C_MEMCPY_H_20051228_

#include "arch_size_t.h"

_LIBC_BEGIN

_ACCESS((write_only, 1))
_ACCESS((read_only, 2, 3))
void *memcpy(void * dest, const void * src, size_t n) _NOEXCEPT;

_LIBC_END

#endif
