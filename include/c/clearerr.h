
#ifndef _C_CLEARERR_H_20051228_
#define _C_CLEARERR_H_20051228_

#include "_file.h"

_LIBC_BEGIN

void __elibc_clearerr(FILE *stream) _NOEXCEPT;
void clearerr(FILE *stream) _NOEXCEPT;

_LIBC_END

#endif
