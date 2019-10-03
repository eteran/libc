
#ifndef FESETENV_20140402_H_
#define FESETENV_20140402_H_

#include "arch_fenv_t.h"

_LIBC_BEGIN

int fesetenv(const fenv_t *envp) _NOEXCEPT;

_LIBC_END

#endif


