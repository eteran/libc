
#ifndef _C_FSCANF_H_20051228_
#define _C_FSCANF_H_20051228_

#include "_file.h"

_LIBC_BEGIN

int fscanf(FILE *stream, const char *format, ...) _NOEXCEPT _NON_NULL(1, 2);

_LIBC_END

#endif
