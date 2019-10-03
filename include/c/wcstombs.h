
#ifndef WCSTOMBS_20051228_H_
#define WCSTOMBS_20051228_H_

#include "arch_wchar_t.h"
#include "arch_size_t.h"

_LIBC_BEGIN

size_t wcstombs(char *s, const wchar_t *wcs, size_t n) _NOEXCEPT;

_LIBC_END

#endif
