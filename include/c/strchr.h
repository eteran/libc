
#ifndef STRCHR_20051228_H_
#define STRCHR_20051228_H_

#ifdef __cplusplus
_PURE const char *strchr(const char *s, int c) _NOEXCEPT  __asm__("strchr");
_PURE       char *strchr(      char *s, int c) _NOEXCEPT  __asm__("strchr");
#else
_PURE char *strchr(const char *s, int c) _NOEXCEPT;
#endif

#endif
