
#ifndef FREAD_20090209_H_
#define FREAD_20090209_H_

#include "arch_size_t.h"
#include "_file.h"

#ifdef __cplusplus
extern "C" {
#endif

size_t __elibc_fread(void *ptr, size_t size, size_t nmemb, FILE *stream) _NOEXCEPT;
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream) _NOEXCEPT;

#ifdef __cplusplus
}
#endif

#endif
