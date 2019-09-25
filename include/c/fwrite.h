
#ifndef FWRITE_20060901_H_
#define FWRITE_20060901_H_

#include "arch_size_t.h"
#include "_file.h"

#ifdef __cplusplus
extern "C" {
#endif

size_t __elibc_fwrite(const void *ptr, size_t size, size_t nelem, FILE *stream) _NOEXCEPT;
size_t fwrite(const void *ptr, size_t size, size_t nelem, FILE *stream) _NOEXCEPT;

#ifdef __cplusplus
}
#endif

#endif




