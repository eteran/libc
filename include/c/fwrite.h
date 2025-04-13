
#ifndef _C_FWRITE_H_20060901_
#define _C_FWRITE_H_20060901_

#include "_file.h"
#include "arch_size_t.h"

_LIBC_BEGIN

size_t fwrite(const void *ptr, size_t size, size_t nelem, FILE *stream) _NOEXCEPT _NON_NULL(1, 4);

_LIBC_END

#endif
