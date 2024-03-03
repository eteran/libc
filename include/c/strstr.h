
#ifndef _C_STRSTR_H_20051228_
#define _C_STRSTR_H_20051228_

#include "arch_size_t.h"

#ifdef __cplusplus
_PURE const char *strnstr(const char *haystack, const char *needle, size_t n) _NOEXCEPT __asm__("strnstr");
_PURE char *strnstr(char *haystack, const char *needle, size_t n) _NOEXCEPT __asm__("strnstr");
_PURE const char *strstr(const char *haystack, const char *needle) _NOEXCEPT __asm__("strstr");
_PURE char *strstr(char *haystack, const char *needle) _NOEXCEPT __asm__("strstr");
#else
_ACCESS((read_only, 1))
_ACCESS((read_only, 2))
_PURE char *strnstr(const char *haystack, const char *needle, size_t n) _NOEXCEPT;

_ACCESS((read_only, 1))
_ACCESS((read_only, 2))
_PURE char *strstr(const char *haystack, const char *needle) _NOEXCEPT;
#endif

#endif
