
#ifndef _C_FEUPDATEENV_H_20140402_
#define _C_FEUPDATEENV_H_20140402_

#include "arch_fenv_t.h"

_LIBC_BEGIN

int feupdateenv(const fenv_t *envp) _NOEXCEPT _NON_NULL(1);

_LIBC_END

#endif
