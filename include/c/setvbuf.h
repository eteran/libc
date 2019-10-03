
#ifndef SETVBUF_20051228_H_
#define SETVBUF_20051228_H_

#include "_file.h"
#include "arch_size_t.h"

_LIBC_BEGIN

int setvbuf(FILE *_RESTRICT stream, char *_RESTRICT buf, int mode , size_t size) _NOEXCEPT;

_LIBC_END

#endif
