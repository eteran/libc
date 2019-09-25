
#ifndef WCSPBRK_20051228_H_
#define WCSPBRK_20051228_H_

#include "arch_wchar_t.h"

#ifdef __cplusplus
_PURE const wchar_t *wcspbrk(const wchar_t *, const wchar_t *) _NOEXCEPT __asm__("wcspbrk");
_PURE       wchar_t *wcspbrk(      wchar_t *, const wchar_t *) _NOEXCEPT __asm__("wcspbrk");
#else
_PURE wchar_t *wcspbrk(const wchar_t *, const wchar_t *) _NOEXCEPT;
#endif

#endif
