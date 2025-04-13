
#ifndef _C_STRLCAT_H_20051228_
#define _C_STRLCAT_H_20051228_

#include "arch_size_t.h"

_LIBC_BEGIN

_ACCESS((read_write, 1))
_ACCESS((read_only, 2))
size_t strlcat(char *dest, const char *src, size_t siz) _NOEXCEPT _NON_NULL(1, 2);

_LIBC_END

#endif
