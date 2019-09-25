
#ifndef SETVBUF_20051228_H_
#define SETVBUF_20051228_H_

#include "_file.h"
#include "arch_size_t.h"

#ifdef __cplusplus
extern "C" {
#endif

int __elibc_setvbuf(FILE *_RESTRICT stream, char *_RESTRICT buf, int mode, size_t size) _NOEXCEPT;
int setvbuf(FILE *_RESTRICT stream, char *_RESTRICT buf, int mode , size_t size) _NOEXCEPT;

#ifdef __cplusplus
}
#endif

#endif
