
#ifndef STRPBRK_20051228_H_
#define STRPBRK_20051228_H_

#ifdef __cplusplus
_PURE const char *strpbrk(const char *s, const char *accept) _NOEXCEPT __asm__("strpbrk");
_PURE       char *strpbrk(      char *s, const char *accept) _NOEXCEPT __asm__("strpbrk");
#else
_PURE char *strpbrk(const char *s, const char *accept) _NOEXCEPT;
#endif

#endif
