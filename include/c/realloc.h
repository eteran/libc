
#ifndef REALLOC_20051228_H_
#define REALLOC_20051228_H_

#include "arch_size_t.h"

#ifdef __cplusplus
extern "C" {
#endif

void *realloc(void *ptr, size_t size) __ELIBC_NOTHROW __attribute__((__alloc_size__(2)));

#ifdef __cplusplus
}
#endif

#endif
