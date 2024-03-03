
#ifndef _C_STRLCAT_H_20051228_
#define _C_STRLCAT_H_20051228_

#include "arch_size_t.h"

_LIBC_BEGIN

_ACCESS((read_write, 1))
_ACCESS((read_only, 2))
size_t strlcat(char *_RESTRICT dest, const char *_RESTRICT src, size_t n) _NOEXCEPT;

_LIBC_END

#endif
