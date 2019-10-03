
#ifndef FSEEK_20051228_H_
#define FSEEK_20051228_H_

#include "_file.h"

_LIBC_BEGIN

int __elibc_fseek(FILE *stream, long offset, int whence) _NOEXCEPT;
int fseek(FILE *stream, long offset, int whence) _NOEXCEPT;

_LIBC_END

#endif
