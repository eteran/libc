
#ifndef FFLUSH_20051228_H_
#define FFLUSH_20051228_H_

#include "_file.h"

_LIBC_BEGIN

int __elibc_fflush(FILE *stream) _NOEXCEPT;
int fflush(FILE *stream) _NOEXCEPT;

_LIBC_END

#endif
