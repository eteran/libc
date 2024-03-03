
#ifndef _C_STRCHR_H_20051228_
#define _C_STRCHR_H_20051228_

#ifdef __cplusplus
_PURE const char *strchr(const char *s, int c) _NOEXCEPT __asm__("strchr");
_PURE char *strchr(char *s, int c) _NOEXCEPT __asm__("strchr");
#else
_ACCESS((read_only, 1))
_PURE char *strchr(const char *s, int c) _NOEXCEPT;
#endif

#endif
