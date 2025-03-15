
#ifndef _C_WCSTOUL_H_20140316_
#define _C_WCSTOUL_H_20140316_

#include "arch_wchar_t.h"

_LIBC_BEGIN

unsigned long int wcstoul(const wchar_t *nptr, wchar_t **endptr,
						  int base) _NOEXCEPT;

_LIBC_END

#endif
