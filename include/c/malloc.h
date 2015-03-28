
#ifndef MALLOC_20051228_H_
#define MALLOC_20051228_H_

#include "arch_size_t.h"

#ifdef __cplusplus
extern "C" {
#endif

void *malloc(size_t size) __ELIBC_NOTHROW __attribute__((__malloc__));

#ifdef __cplusplus
}
#endif

#endif
