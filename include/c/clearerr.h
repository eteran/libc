
#ifndef _C_CLEARERR_H_20051228_
#define _C_CLEARERR_H_20051228_

#include "_file.h"

_LIBC_BEGIN

int __elibc_clearerr(FILE *stream) _NOEXCEPT _NON_NULL(1);
void clearerr(FILE *stream) _NOEXCEPT _NON_NULL(1);

_LIBC_END

#endif
