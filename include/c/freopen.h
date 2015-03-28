
#ifndef FREOPEN_20070504_H_
#define FREOPEN_20070504_H_

#include "_file.h"

#ifdef __cplusplus
extern "C" {
#endif

FILE *__elibc_freopen(const char *path, const char *mode, FILE *stream) __ELIBC_NOTHROW;
FILE *freopen(const char *path, const char *mode, FILE *stream) __ELIBC_NOTHROW;

#ifdef __cplusplus
}
#endif

#endif
