
#ifndef _C_FEHOLDEXCEPT_H_20140402_
#define _C_FEHOLDEXCEPT_H_20140402_

#include "arch_fenv_t.h"

_LIBC_BEGIN

int feholdexcept(fenv_t *envp) _NOEXCEPT;

_LIBC_END

#endif
