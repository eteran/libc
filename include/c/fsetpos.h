
#ifndef FSETPOS_20061013_H_
#define FSETPOS_20061013_H_

#include "_file.h"
#include "arch_fpos_t.h"

#ifdef __cplusplus
extern "C" {
#endif

int fsetpos(FILE *stream, const fpos_t *pos) __ELIBC_NOTHROW;

#ifdef __cplusplus
}
#endif

#endif
