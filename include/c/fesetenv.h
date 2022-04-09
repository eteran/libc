
#ifndef _C_FESETENV_H_20140402_
#define _C_FESETENV_H_20140402_

#include "arch_fenv_t.h"

_LIBC_BEGIN

int fesetenv(const fenv_t *envp) _NOEXCEPT;

_LIBC_END

#endif
