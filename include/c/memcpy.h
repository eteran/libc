
#ifndef MEMCPY_20051228_H_
#define MEMCPY_20051228_H_

#include "arch_size_t.h"

#ifdef __cplusplus
extern "C" {
#endif

void *memcpy(void * _RESTRICT dest, const void * _RESTRICT src, size_t n) _NOEXCEPT;

#ifdef __cplusplus
}
#endif

#endif
