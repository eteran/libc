
#ifndef _C_STRTOK_H_20051228_
#define _C_STRTOK_H_20051228_

_LIBC_BEGIN

_ACCESS((read_write, 1))
_ACCESS((read_only, 2))
char *strtok(char *_RESTRICT s, const char *_RESTRICT delim) _NOEXCEPT;

_ACCESS((read_write, 1))
_ACCESS((read_only, 2))
_ACCESS((read_write, 3))
char *strtok_r(char *_RESTRICT s, const char *_RESTRICT delim, char **ptrptr) _NOEXCEPT;

_LIBC_END

#endif
