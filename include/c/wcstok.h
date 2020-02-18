
#ifndef _C_WCSTOK_H_20140316_
#define _C_WCSTOK_H_20140316_

#include "arch_wchar_t.h"

_LIBC_BEGIN

wchar_t *wcstok(wchar_t *_RESTRICT s, const wchar_t *_RESTRICT delim) _NOEXCEPT;
wchar_t *wcstok_r(wchar_t *_RESTRICT s, const wchar_t *_RESTRICT delim, wchar_t **ptrptr) _NOEXCEPT;

_LIBC_END

#endif
