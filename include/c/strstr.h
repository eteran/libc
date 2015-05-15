
#ifndef STRSTR_20051228_H_
#define STRSTR_20051228_H_

#include "arch_size_t.h"

#ifdef __cplusplus
__ELIBC_PURE const char *strnstr(const char *haystack, const char *needle, size_t n) __ELIBC_NOTHROW __asm__("strnstr");
__ELIBC_PURE       char *strnstr(      char *haystack, const char *needle, size_t n) __ELIBC_NOTHROW __asm__("strnstr");

__ELIBC_PURE const char *strstr(const char *haystack, const char *needle) __ELIBC_NOTHROW __asm__("strstr");
__ELIBC_PURE       char *strstr(      char *haystack, const char *needle) __ELIBC_NOTHROW __asm__("strstr");
#else
__ELIBC_PURE char *strnstr(const char *haystack, const char *needle, size_t n) __ELIBC_NOTHROW;
__ELIBC_PURE char *strstr(const char *haystack, const char *needle) __ELIBC_NOTHROW;
#endif

#endif
