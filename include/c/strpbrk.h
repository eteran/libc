
#ifndef STRPBRK_20051228_H_
#define STRPBRK_20051228_H_

#ifdef __cplusplus
const char *strpbrk(const char *s, const char *accept) __ELIBC_NOTHROW __asm__("strpbrk");
      char *strpbrk(      char *s, const char *accept) __ELIBC_NOTHROW __asm__("strpbrk");
#else
char *strpbrk(const char *s, const char *accept) __ELIBC_NOTHROW;
#endif

#endif
