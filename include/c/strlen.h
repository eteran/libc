
#ifndef _C_STRLEN_H_20051228_
#define _C_STRLEN_H_20051228_

#include "arch_size_t.h"

_LIBC_BEGIN

_ACCESS((read_only, 1))
_PURE size_t strlen(const char *s) _NOEXCEPT;

_LIBC_END

#endif
