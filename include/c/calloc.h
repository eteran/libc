
#ifndef CALLOC_20051228_H_
#define CALLOC_20051228_H_

#include "arch_size_t.h"

#ifdef __cplusplus
extern "C" {
#endif

void *calloc(size_t nmemb, size_t size) __ELIBC_NOTHROW __attribute__((__alloc_size__(1, 2)));

#ifdef __cplusplus
}
#endif

#endif
