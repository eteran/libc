
#ifndef _C_STRTOK_H_20051228_
#define _C_STRTOK_H_20051228_

_LIBC_BEGIN

_ACCESS((read_write, 1))
_ACCESS((read_only, 2))
char *strtok(char *s, const char *delim) _NOEXCEPT _NON_NULL(2);

_ACCESS((read_write, 1))
_ACCESS((read_only, 2))
_ACCESS((read_write, 3))
char *strtok_r(char *s, const char *delim, char **saveptr) _NOEXCEPT _NON_NULL(2, 3);

_LIBC_END

#endif
