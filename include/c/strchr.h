
#ifndef STRCHR_20051228_H_
#define STRCHR_20051228_H_

#ifdef __cplusplus
const char *strchr(const char *s, int c) __ELIBC_NOTHROW  __asm__("strchr");
      char *strchr(      char *s, int c) __ELIBC_NOTHROW  __asm__("strchr");
#else
char *strchr(const char *s, int c) __ELIBC_NOTHROW;
#endif

#endif
