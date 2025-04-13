
#ifndef _C_FSEEK_H_20051228_
#define _C_FSEEK_H_20051228_

#include "_file.h"

_LIBC_BEGIN

int __elibc_fseek(FILE *stream, long offset, int whence) _NOEXCEPT _NON_NULL(1);
int fseek(FILE *stream, long offset, int whence) _NOEXCEPT _NON_NULL(1);

_LIBC_END

#endif
