
#ifndef VFPRINTF_20051228_H_
#define VFPRINTF_20051228_H_

#include "arch_va_list.h"
#include "_file.h"

#ifdef __cplusplus
extern "C" {
#endif

int vfprintf(FILE *_RESTRICT stream, const char *_RESTRICT format, va_list ap) _NOEXCEPT __attribute__((__format__ (printf, 2, 0)));

#ifdef __cplusplus
}
#endif

#endif
