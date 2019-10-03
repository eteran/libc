
#ifndef CLEARERR_20051228_H_
#define CLEARERR_20051228_H_

#include "_file.h"

_LIBC_BEGIN

void __elibc_clearerr(FILE *stream) _NOEXCEPT;
void clearerr(FILE *stream) _NOEXCEPT;

_LIBC_END

#endif
