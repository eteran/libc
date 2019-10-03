
#ifndef FWIDE_20140316_H_
#define FWIDE_20140316_H_

#include "_file.h"

_LIBC_BEGIN

int __elibc_fwide(FILE *stream, int mode) _NOEXCEPT;
int fwide(FILE *stream, int mode) _NOEXCEPT;

_LIBC_END

#endif
