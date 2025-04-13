
#ifndef _C_FCLOSE_H_20051228_
#define _C_FCLOSE_H_20051228_

#include "_file.h"

_LIBC_BEGIN

int __elibc_fclose(FILE *stream) _NOEXCEPT _NON_NULL(1);
int fclose(FILE *stream) _NOEXCEPT _NON_NULL(1);

_LIBC_END

#endif
