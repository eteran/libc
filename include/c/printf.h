
#ifndef _C_PRINTF_H_20051228_
#define _C_PRINTF_H_20051228_

_LIBC_BEGIN

int printf(const char *_RESTRICT format, ...) _NOEXCEPT __attribute__((__format__(printf, 1, 2)));

_LIBC_END

#endif
