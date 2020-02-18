
#ifndef _C_FSETPOS_H_20061013_
#define _C_FSETPOS_H_20061013_

#include "_file.h"
#include "arch_fpos_t.h"

_LIBC_BEGIN

int fsetpos(FILE *stream, const fpos_t *pos) _NOEXCEPT;

_LIBC_END

#endif
