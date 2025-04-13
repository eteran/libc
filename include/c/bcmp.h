
#ifndef _C_BCMP_H_20051228_
#define _C_BCMP_H_20051228_

#include "arch_size_t.h"

_LIBC_BEGIN

_DEPRECATED _PURE int bcmp(const void *s1, const void *s2, size_t n) _NOEXCEPT _NON_NULL(1, 2);

_LIBC_END

#endif
