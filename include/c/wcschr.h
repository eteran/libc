
#ifndef WCSCHR_20051228_H_
#define WCSCHR_20051228_H_

#include "arch_wchar_t.h"

#ifdef __cplusplus
_PURE const wchar_t *wcschr(const wchar_t *s, wchar_t c) _NOEXCEPT __asm__("wcschr");
_PURE       wchar_t *wcschr(      wchar_t *s, wchar_t c) _NOEXCEPT __asm__("wcschr");
#else
_PURE wchar_t *wcschr(const wchar_t *s, wchar_t c) _NOEXCEPT;
#endif

#endif
