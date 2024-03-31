
#ifndef _C_FEGETEXCEPTFLAG_H_20140402_
#define _C_FEGETEXCEPTFLAG_H_20140402_

#include "arch_fexcept_t.h"

_LIBC_BEGIN

int fegetexceptflag(fexcept_t *fp, int mask) _NOEXCEPT;

_LIBC_END

#endif
