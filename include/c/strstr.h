
#ifndef STRSTR_20051228_H_
#define STRSTR_20051228_H_

#include "arch_size_t.h"

#ifdef __cplusplus
const char *strnstr(const char *haystack, const char *needle, size_t n) __ELIBC_NOTHROW __asm__("strnstr");
      char *strnstr(      char *haystack, const char *needle, size_t n) __ELIBC_NOTHROW __asm__("strnstr");

const char *strstr(const char *haystack, const char *needle) __ELIBC_NOTHROW __asm__("strstr");
      char *strstr(      char *haystack, const char *needle) __ELIBC_NOTHROW __asm__("strstr");
#else
char *strnstr(const char *haystack, const char *needle, size_t n) __ELIBC_NOTHROW;
char *strstr(const char *haystack, const char *needle) __ELIBC_NOTHROW;
#endif

#endif
