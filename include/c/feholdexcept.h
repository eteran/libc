
#ifndef FEHOLDEXCEPT_20140402_H_
#define FEHOLDEXCEPT_20140402_H_

#include "arch_fenv_t.h"

#ifdef __cplusplus
extern "C" {
#endif

int feholdexcept(fenv_t *envp) _NOEXCEPT;

#ifdef __cplusplus
}
#endif

#endif


