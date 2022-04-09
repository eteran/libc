
#ifndef _C_FWPRINTF_H_20140316_
#define _C_FWPRINTF_H_20140316_

#include "_file.h"
#include "arch_wchar_t.h"

_LIBC_BEGIN

int fwprintf(FILE *, const wchar_t *, ...) _NOEXCEPT;

_LIBC_END

#endif
