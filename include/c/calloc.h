
#ifndef _C_CALLOC_H_20051228_
#define _C_CALLOC_H_20051228_

#include "arch_size_t.h"

_LIBC_BEGIN

void *calloc(size_t nmemb, size_t size) _NOEXCEPT
	__attribute__((__malloc__));

_LIBC_END

#endif
