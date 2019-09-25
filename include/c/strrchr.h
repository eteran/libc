
#ifndef STRRCHR_20051228_H_
#define STRRCHR_20051228_H_

#ifdef __cplusplus
_PURE const char *strrchr(const char *s, int c) _NOEXCEPT __asm__("strrchr");
_PURE       char *strrchr(      char *s, int c) _NOEXCEPT __asm__("strrchr");
#else
_PURE char *strrchr(const char *s, int c) _NOEXCEPT;
#endif

#endif
