
#ifndef FOPEN_20051228_H_
#define FOPEN_20051228_H_

#include "_file.h"

#ifdef __cplusplus
extern "C" {
#endif

FILE *fopen(const char *path, const char *mode) __ELIBC_NOTHROW;

#ifdef __cplusplus
}
#endif

#endif
