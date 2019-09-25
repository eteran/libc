
#ifndef FPUTS_20051228_H_
#define FPUTS_20051228_H_

#include "_file.h"

#ifdef __cplusplus
extern "C" {
#endif

int __elibc_fputs(const char *_RESTRICT s, FILE *_RESTRICT stream) _NOEXCEPT;
int fputs(const char *_RESTRICT s, FILE *_RESTRICT stream) _NOEXCEPT;

#ifdef __cplusplus
}
#endif

#endif
