
#ifndef FGETPOS_20061013_H_
#define FGETPOS_20061013_H_

#include "_file.h"
#include "arch_fpos_t.h"

_LIBC_BEGIN

int fgetpos(FILE *stream, fpos_t *pos) _NOEXCEPT;

_LIBC_END

#endif
