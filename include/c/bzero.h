
#ifndef _C_BZERO_H_20051228_
#define _C_BZERO_H_20051228_

#include "arch_size_t.h"

_LIBC_BEGIN

_DEPRECATED void bzero(void *s, size_t n) _NOEXCEPT _NON_NULL(1);

_LIBC_END

#endif
