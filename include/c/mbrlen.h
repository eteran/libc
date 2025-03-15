
#ifndef _C_MBRLEN_H_20140316_
#define _C_MBRLEN_H_20140316_

#include "_mbstate_t.h"
#include "arch_size_t.h"

_LIBC_BEGIN

size_t mbrlen(const char *s, size_t n, mbstate_t *ps) _NOEXCEPT;

_LIBC_END

#endif
