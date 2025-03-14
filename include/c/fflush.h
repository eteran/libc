
#ifndef _C_FFLUSH_H_20051228_
#define _C_FFLUSH_H_20051228_

#include "_file.h"

_LIBC_BEGIN

int __elibc_fflush(FILE *stream) _NOEXCEPT;
int fflush(FILE *stream) _NOEXCEPT;

_LIBC_END

#endif
