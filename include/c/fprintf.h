
#ifndef FPRINTF_20051228_H_
#define FPRINTF_20051228_H_

#include "_file.h"

_LIBC_BEGIN

int fprintf(FILE *_RESTRICT stream, const char *_RESTRICT format, ...) _NOEXCEPT __attribute__((__format__ (printf, 2, 3)));

_LIBC_END

#endif
