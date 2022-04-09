
#ifndef _C_FGETWS_H_20140316_
#define _C_FGETWS_H_20140316_

#include "_file.h"
#include "arch_wchar_t.h"

_LIBC_BEGIN

wchar_t *fgetws(wchar_t *ws, int n, FILE *stream) _NOEXCEPT;

_LIBC_END

#endif
