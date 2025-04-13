
#ifndef _C_FPUTS_H_20051228_
#define _C_FPUTS_H_20051228_

#include "_file.h"

_LIBC_BEGIN

int fputs(const char *s, FILE *stream) _NOEXCEPT _NON_NULL(1, 2);

_LIBC_END

#endif
