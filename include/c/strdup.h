
#ifndef _C_STRDUP_H_20051228_
#define _C_STRDUP_H_20051228_

_LIBC_BEGIN

_ACCESS((read_only, 1))
char *strdup(const char *s) _NOEXCEPT __attribute__((__malloc__));

_LIBC_END

#endif
