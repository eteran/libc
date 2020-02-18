
#ifndef _C_QSORT_H_20051228_
#define _C_QSORT_H_20051228_

#include "arch_size_t.h"
#include "_compar_t.h"

_LIBC_BEGIN

void qsort(void *base, size_t nmemb, size_t size, __compar_fn_t compar);

_LIBC_END

#endif
