
#ifndef _C_VFSCANF_H_20051228_
#define _C_VFSCANF_H_20051228_

#include "_file.h"

_LIBC_BEGIN

int vfscanf(FILE *_RESTRICT stream, const char *_RESTRICT format, va_list ap) _NOEXCEPT;

_LIBC_END

#endif
