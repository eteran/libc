
#ifndef STRNCPY_20051228_H_
#define STRNCPY_20051228_H_

#include "arch_size_t.h"

#ifdef __cplusplus
extern "C" {
#endif

char *strncpy(char *_RESTRICT dest, const char *_RESTRICT src, size_t n) _NOEXCEPT;

#ifdef __cplusplus
}
#endif

#endif
