
#ifndef SPRINTF_20051228_H_
#define SPRINTF_20051228_H_

_LIBC_BEGIN

int sprintf(char *_RESTRICT str, const char *_RESTRICT format, ...) _NOEXCEPT __attribute__((__format__ (printf, 2, 3)));

_LIBC_END

#endif
