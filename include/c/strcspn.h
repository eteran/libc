
#ifndef _C_STRCSPN_H_20051228_
#define _C_STRCSPN_H_20051228_

#include "arch_size_t.h"

_LIBC_BEGIN

_ACCESS((read_only, 1))
_ACCESS((read_only, 2))
_PURE size_t strcspn(const char *s, const char *reject) _NOEXCEPT;

_LIBC_END

#endif
