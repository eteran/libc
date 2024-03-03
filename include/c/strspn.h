
#ifndef _C_STRSPN_H_20051228_
#define _C_STRSPN_H_20051228_

#include "arch_size_t.h"

_LIBC_BEGIN

_ACCESS((read_only, 1))
_ACCESS((read_only, 2))
_PURE size_t strspn(const char *s, const char *accept) _NOEXCEPT;

_LIBC_END

#endif
