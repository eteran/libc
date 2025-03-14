
#ifndef _C_FWSCANF_H_20140316_
#define _C_FWSCANF_H_20140316_

#include "_file.h"
#include "arch_wchar_t.h"

_LIBC_BEGIN

int fwscanf(FILE * stream, const wchar_t *format, ...) _NOEXCEPT;

_LIBC_END

#endif
