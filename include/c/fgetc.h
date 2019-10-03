
#ifndef FGETC_20051228_H_
#define FGETC_20051228_H_

#include "_file.h"

_LIBC_BEGIN

int __elibc_fgetc(FILE *stream) _NOEXCEPT;
int fgetc(FILE *stream) _NOEXCEPT;

_LIBC_END

#endif
