
#ifndef _C_MEMMOVE_H_20051228_
#define _C_MEMMOVE_H_20051228_

#include "arch_size_t.h"

_LIBC_BEGIN

_ACCESS((write_only, 1))
_ACCESS((read_only, 2, 3))
void *memmove(void *_RESTRICT dest, const void *_RESTRICT src, size_t n) _NOEXCEPT;

_LIBC_END

#endif
