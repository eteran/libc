
#ifndef FGETPOS_20061013_H_
#define FGETPOS_20061013_H_

#include "_file.h"
#include "arch_fpos_t.h"

#ifdef __cplusplus
extern "C" {
#endif

int fgetpos(FILE *stream, fpos_t *pos) __ELIBC_NOTHROW;

#ifdef __cplusplus
}
#endif

#endif
