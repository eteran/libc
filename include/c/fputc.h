
#ifndef _C_FPUTC_H_20051228_
#define _C_FPUTC_H_20051228_

#include "_file.h"

_LIBC_BEGIN

int __elibc_fputc(int c, FILE *stream, int wide) _NOEXCEPT _NON_NULL(2);
int fputc(int c, FILE *stream) _NOEXCEPT _NON_NULL(2);

_LIBC_END

#endif
