
#ifndef _C_STRXFRM_H_20051228_
#define _C_STRXFRM_H_20051228_

#include "arch_size_t.h"

_LIBC_BEGIN

_ACCESS((write_only, 1))
_ACCESS((read_only, 2))
size_t strxfrm(char *dest, const char *src, size_t n) _NOEXCEPT _NON_NULL(1, 2);

_LIBC_END

#endif
