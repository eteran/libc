
#ifndef STRCHR_20051228_H_
#define STRCHR_20051228_H_

#ifdef __cplusplus
__ELIBC_PURE const char *strchr(const char *s, int c) __ELIBC_NOTHROW  __asm__("strchr");
__ELIBC_PURE       char *strchr(      char *s, int c) __ELIBC_NOTHROW  __asm__("strchr");
#else
__ELIBC_PURE char *strchr(const char *s, int c) __ELIBC_NOTHROW;
#endif

#endif
