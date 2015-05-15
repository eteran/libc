
#ifndef STRPBRK_20051228_H_
#define STRPBRK_20051228_H_

#ifdef __cplusplus
__ELIBC_PURE const char *strpbrk(const char *s, const char *accept) __ELIBC_NOTHROW __asm__("strpbrk");
__ELIBC_PURE       char *strpbrk(      char *s, const char *accept) __ELIBC_NOTHROW __asm__("strpbrk");
#else
__ELIBC_PURE char *strpbrk(const char *s, const char *accept) __ELIBC_NOTHROW;
#endif

#endif
