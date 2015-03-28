
#ifndef BSEARCH_20051228_H_
#define BSEARCH_20051228_H_

#include "arch_size_t.h"
#include "_compar_t.h"

#ifdef __cplusplus
extern "C" {
#endif

void *bsearch(const void *key, const void *base, size_t nmemb, size_t size, _compar_t compar);

#ifdef __cplusplus
}
#endif

#endif


