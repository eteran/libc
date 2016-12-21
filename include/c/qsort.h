
#ifndef QSORT_20051228_H_
#define QSORT_20051228_H_

#include "arch_size_t.h"
#include "_compar_t.h"

#ifdef __cplusplus
extern "C" {
#endif

void qsort(void *base, size_t nmemb, size_t size, __compar_fn_t compar);

#ifdef __cplusplus
}
#endif

#endif
