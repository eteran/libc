
#ifndef FPRINTF_20051228_H_
#define FPRINTF_20051228_H_

#include "_file.h"

#ifdef __cplusplus
extern "C" {
#endif

int fprintf(FILE *_RESTRICT stream, const char *_RESTRICT format, ...) _NOEXCEPT __attribute__((__format__ (printf, 2, 3)));

#ifdef __cplusplus
}
#endif

#endif
