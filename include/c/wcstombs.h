
#ifndef _C_WCSTOMBS_H_20051228_
#define _C_WCSTOMBS_H_20051228_

#include "arch_size_t.h"
#include "arch_wchar_t.h"

_LIBC_BEGIN

size_t wcstombs(char *dest, const wchar_t *src, size_t n) _NOEXCEPT;

_LIBC_END

#endif
