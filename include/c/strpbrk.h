
#ifndef _C_STRPBRK_H_20051228_
#define _C_STRPBRK_H_20051228_

#ifdef __cplusplus
_PURE const char *strpbrk(const char *s, const char *accept) _NOEXCEPT __asm__("strpbrk");
_PURE       char *strpbrk(      char *s, const char *accept) _NOEXCEPT __asm__("strpbrk");
#else
_PURE char *strpbrk(const char *s, const char *accept) _NOEXCEPT;
#endif

#endif
