
#ifndef _C_WCSSTR_H_20051228_
#define _C_WCSSTR_H_20051228_

#include "arch_wchar_t.h"

#ifdef __cplusplus
_PURE const wchar_t *wcsstr(const wchar_t *, const wchar_t *) _NOEXCEPT __asm__("wcsstr");
_PURE wchar_t *wcsstr(wchar_t *, const wchar_t *) _NOEXCEPT __asm__("wcsstr");
_PURE const wchar_t *wcsstr(const wchar_t *haystack, const wchar_t *needle, size_t n) _NOEXCEPT __asm__("wcsnstr");
_PURE wchar_t *wcsstr(wchar_t *haystack, wchar_t *needle, size_t n) _NOEXCEPT __asm__("wcsnstr");
#else
_PURE wchar_t *wcsstr(const wchar_t *, const wchar_t *) _NOEXCEPT;
_PURE wchar_t *wcsnstr(const wchar_t *haystack, const wchar_t *needle, size_t n) _NOEXCEPT;
#endif

#endif
