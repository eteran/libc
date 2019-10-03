
#ifndef WCRTOMB_20140316_H_
#define WCRTOMB_20140316_H_

#include "arch_wchar_t.h"
#include "arch_size_t.h"

_LIBC_BEGIN

size_t wcrtomb(char *, wchar_t, mbstate_t *) _NOEXCEPT;

_LIBC_END

#endif
