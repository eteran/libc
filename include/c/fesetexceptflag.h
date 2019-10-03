
#ifndef FESETEXCEPTFLAG_20140402_H_
#define FESETEXCEPTFLAG_20140402_H_

#include "arch_fexcept_t.h"

_LIBC_BEGIN

int fesetexceptflag(const fexcept_t *flagp, int excepts) _NOEXCEPT;

_LIBC_END

#endif


