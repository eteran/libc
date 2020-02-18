
#ifndef _C_FWIDE_H_20140316_
#define _C_FWIDE_H_20140316_

#include "_file.h"

_LIBC_BEGIN

int __elibc_fwide(FILE *stream, int mode) _NOEXCEPT;
int fwide(FILE *stream, int mode) _NOEXCEPT;

_LIBC_END

#endif
