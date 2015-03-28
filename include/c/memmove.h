
#ifndef MEMMOVE_20051228_H_
#define MEMMOVE_20051228_H_

#include "arch_size_t.h"

#ifdef __cplusplus
extern "C" {
#endif

void *memmove(void *dest, const void *src, size_t n) __ELIBC_NOTHROW;

#ifdef __cplusplus
}
#endif

#endif
