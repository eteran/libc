
#ifndef _C_FGETC_H_20051228_
#define _C_FGETC_H_20051228_

#include "_file.h"

_LIBC_BEGIN

int __elibc_fgetc(FILE *stream) _NOEXCEPT;
int fgetc(FILE *stream) _NOEXCEPT;

_LIBC_END

#endif
