
#ifndef STRRCHR_20051228_H_
#define STRRCHR_20051228_H_

#ifdef __cplusplus
__ELIBC_PURE const char *strrchr(const char *s, int c) __ELIBC_NOTHROW __asm__("strrchr");
__ELIBC_PURE       char *strrchr(      char *s, int c) __ELIBC_NOTHROW __asm__("strrchr");
#else
__ELIBC_PURE char *strrchr(const char *s, int c) __ELIBC_NOTHROW;
#endif

#endif
