
#ifndef FGETS_20051228_H_
#define FGETS_20051228_H_

#include "_file.h"

#ifdef __cplusplus
extern "C" {
#endif

char *__elibc_fgets(char *_RESTRICT s, int size, FILE *_RESTRICT stream) _NOEXCEPT;
char *fgets(char *_RESTRICT s, int size, FILE *_RESTRICT stream) _NOEXCEPT;

#ifdef __cplusplus
}
#endif

#endif
