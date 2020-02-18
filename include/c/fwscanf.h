
#ifndef _C_FWSCANF_H_20140316_
#define _C_FWSCANF_H_20140316_

#include "arch_wchar_t.h"
#include "_file.h"

_LIBC_BEGIN

int fwscanf(FILE *_RESTRICT stream, const wchar_t *format, ...) _NOEXCEPT;

_LIBC_END

#endif
