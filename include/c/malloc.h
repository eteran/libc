
#ifndef _C_MALLOC_H_20051228_
#define _C_MALLOC_H_20051228_

#include "arch_size_t.h"

_LIBC_BEGIN

void *malloc(size_t size) _NOEXCEPT __attribute__((__malloc__, __alloc_size__(1)));

_LIBC_END

#endif
