
#ifndef _C_STRRCHR_H_20051228_
#define _C_STRRCHR_H_20051228_

#ifdef __cplusplus
_PURE const char *strrchr(const char *s, int c) _NOEXCEPT __asm__("strrchr");
_PURE       char *strrchr(      char *s, int c) _NOEXCEPT __asm__("strrchr");
#else
_PURE char *strrchr(const char *s, int c) _NOEXCEPT;
#endif

#endif
