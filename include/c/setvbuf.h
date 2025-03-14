
#ifndef _C_SETVBUF_H_20051228_
#define _C_SETVBUF_H_20051228_

#include "_file.h"
#include "arch_size_t.h"

_LIBC_BEGIN

int setvbuf(FILE * stream, char * buf, int mode, size_t size) _NOEXCEPT;

_LIBC_END

#endif
