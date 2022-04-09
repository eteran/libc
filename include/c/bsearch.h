
#ifndef _C_BSEARCH_H_20051228_
#define _C_BSEARCH_H_20051228_

#include "_compar_t.h"
#include "arch_size_t.h"

_LIBC_BEGIN

void *bsearch(const void *key, const void *base, size_t nmemb, size_t size, __compar_fn_t compar);

_LIBC_END

#endif
