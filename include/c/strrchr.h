
#ifndef STRRCHR_20051228_H_
#define STRRCHR_20051228_H_

#ifdef __cplusplus
const char *strrchr(const char *s, int c) __ELIBC_NOTHROW __asm__("strrchr");
      char *strrchr(      char *s, int c) __ELIBC_NOTHROW __asm__("strrchr");
#else
char *strrchr(const char *s, int c) __ELIBC_NOTHROW;
#endif

#endif
