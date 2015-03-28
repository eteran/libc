
#ifndef MEMCPY_20051228_H_
#define MEMCPY_20051228_H_

#include "arch_size_t.h"

#ifdef __cplusplus
extern "C" {
#endif

void *memcpy(void * __ELIBC_RESTRICT dest, const void * __ELIBC_RESTRICT src, size_t n) __ELIBC_NOTHROW;

#ifdef __cplusplus
}
#endif

#endif
