
#ifndef FWSCANF_20140316_H_
#define FWSCANF_20140316_H_

#include "arch_wchar_t.h"
#include "_file.h"

_LIBC_BEGIN

int fwscanf(FILE *_RESTRICT stream, const wchar_t *format, ...) _NOEXCEPT;

_LIBC_END

#endif
