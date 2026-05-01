
#ifndef _C_FREAD_H_20090209_
#define _C_FREAD_H_20090209_

#include "_file.h"
#include "arch_size_t.h"

_LIBC_BEGIN

size_t fread(void *_RESTRICT ptr, size_t size, size_t nmemb, FILE *_RESTRICT stream) _NOEXCEPT _NON_NULL(1, 4);

_LIBC_END

#endif
