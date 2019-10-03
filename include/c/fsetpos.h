
#ifndef FSETPOS_20061013_H_
#define FSETPOS_20061013_H_

#include "_file.h"
#include "arch_fpos_t.h"

_LIBC_BEGIN

int fsetpos(FILE *stream, const fpos_t *pos) _NOEXCEPT;

_LIBC_END

#endif
