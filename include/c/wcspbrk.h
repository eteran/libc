
#ifndef _C_WCSPBRK_H_20051228_
#define _C_WCSPBRK_H_20051228_

#include "arch_wchar_t.h"

#ifdef __cplusplus
_PURE const wchar_t *wcspbrk(const wchar_t *, const wchar_t *) _NOEXCEPT __asm__("wcspbrk");
_PURE wchar_t *wcspbrk(wchar_t *, const wchar_t *) _NOEXCEPT __asm__("wcspbrk");
#else
_PURE wchar_t *wcspbrk(const wchar_t *, const wchar_t *) _NOEXCEPT;
#endif

#endif
