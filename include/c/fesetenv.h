
#ifndef FESETENV_20140402_H_
#define FESETENV_20140402_H_

#include "arch_fenv_t.h"

#ifdef __cplusplus
extern "C" {
#endif

int fesetenv(const fenv_t *envp) __ELIBC_NOTHROW;

#ifdef __cplusplus
}
#endif

#endif


