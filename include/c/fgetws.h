
#ifndef FGETWS_20140316_H_
#define FGETWS_20140316_H_

#include "arch_wchar_t.h"
#include "_file.h"

_LIBC_BEGIN

wchar_t *fgetws(wchar_t *ws, int n, FILE *stream) _NOEXCEPT;

_LIBC_END

#endif
