
#ifndef _C_FESETEXCEPTFLAG_H_20140402_
#define _C_FESETEXCEPTFLAG_H_20140402_

#include "arch_fexcept_t.h"

_LIBC_BEGIN

int fesetexceptflag(const fexcept_t *flagp, int excepts) _NOEXCEPT;

_LIBC_END

#endif
