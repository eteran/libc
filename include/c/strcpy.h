
#ifndef _C_STRCPY_H_20051228_
#define _C_STRCPY_H_20051228_

_LIBC_BEGIN

_ACCESS((write_only, 1))
_ACCESS((read_only, 2))
char *strcpy(char *dest, const char *src) _NOEXCEPT;

_LIBC_END

#endif
