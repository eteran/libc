
#ifndef _C_MBTOWC_H_20051228_
#define _C_MBTOWC_H_20051228_

#include "arch_size_t.h"
#include "arch_wchar_t.h"

_LIBC_BEGIN

int mbtowc(wchar_t *pwc, const char *s, size_t n) _NOEXCEPT;

_LIBC_END

#endif
