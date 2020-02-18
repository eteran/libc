
#ifndef _C_MBSTOWCS_H_20051228_
#define _C_MBSTOWCS_H_20051228_

#include "arch_wchar_t.h"
#include "arch_size_t.h"

_LIBC_BEGIN

size_t mbstowcs(wchar_t *pwcs, const char *s, size_t n) _NOEXCEPT;

_LIBC_END

#endif
