
#ifndef _C_BCOPY_H_20051228_
#define _C_BCOPY_H_20051228_

#include "arch_size_t.h"

_LIBC_BEGIN

_DEPRECATED void bcopy(const void *src, void *dest, size_t n) _NOEXCEPT _NON_NULL(1, 2);

_LIBC_END

#endif
