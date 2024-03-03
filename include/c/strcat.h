
#ifndef _C_STRCAT_H_20051228_
#define _C_STRCAT_H_20051228_

_LIBC_BEGIN

_ACCESS((read_write, 1))
_ACCESS((read_only, 2))
char *strcat(char *_RESTRICT dest, const char *_RESTRICT src) _NOEXCEPT;

_LIBC_END

#endif
