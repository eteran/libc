
#ifndef _C_FGETPOS_H_20061013_
#define _C_FGETPOS_H_20061013_

#include "_file.h"
#include "arch_fpos_t.h"

_LIBC_BEGIN

int fgetpos(FILE *stream, fpos_t *pos) _NOEXCEPT _NON_NULL(1, 2);

_LIBC_END

#endif
