
#ifndef FEGETEXCEPTFLAG_20140402_H_
#define FEGETEXCEPTFLAG_20140402_H_

#include "arch_fexcept_t.h"

#ifdef __cplusplus
extern "C" {
#endif

int fegetexceptflag(fexcept_t *flagp, int excepts) _NOEXCEPT;

#ifdef __cplusplus
}
#endif

#endif


