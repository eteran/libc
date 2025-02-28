
#ifndef _C_REALLOC_H_20051228_
#define _C_REALLOC_H_20051228_

#include "arch_size_t.h"

_LIBC_BEGIN

void *realloc(void *ptr, size_t size) _NOEXCEPT __attribute__((__malloc__, __alloc_size__(2)));

_LIBC_END

#endif
