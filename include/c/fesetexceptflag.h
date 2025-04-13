
#ifndef _C_FESETEXCEPTFLAG_H_20140402_
#define _C_FESETEXCEPTFLAG_H_20140402_

#include "arch_fexcept_t.h"

_LIBC_BEGIN

int fesetexceptflag(const fexcept_t *fp, int mask) _NOEXCEPT _NON_NULL(1);

_LIBC_END

#endif
