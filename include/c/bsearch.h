
#ifndef BSEARCH_20051228_H_
#define BSEARCH_20051228_H_

#include "arch_size_t.h"
#include "_compar_t.h"

_LIBC_BEGIN

void *bsearch(const void *key, const void *base, size_t nmemb, size_t size, __compar_fn_t compar);

_LIBC_END

#endif


