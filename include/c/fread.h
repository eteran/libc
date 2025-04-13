
#ifndef _C_FREAD_H_20090209_
#define _C_FREAD_H_20090209_

#include "_file.h"
#include "arch_size_t.h"

_LIBC_BEGIN

size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream) _NOEXCEPT _NON_NULL(1, 4);

_LIBC_END

#endif
