
#ifndef BCOPY_20051228_H_
#define BCOPY_20051228_H_

#include "arch_size_t.h"

#ifdef __cplusplus
extern "C" {
#endif

void bcopy(const void *src, void *dest, size_t n) __ELIBC_NOTHROW __ELIBC_DEPRECATED;

#ifdef __cplusplus
}
#endif

#endif
