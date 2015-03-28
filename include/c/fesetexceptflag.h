
#ifndef FESETEXCEPTFLAG_20140402_H_
#define FESETEXCEPTFLAG_20140402_H_

#include "arch_fexcept_t.h"

#ifdef __cplusplus
extern "C" {
#endif

int fesetexceptflag(const fexcept_t *flagp, int excepts) __ELIBC_NOTHROW;

#ifdef __cplusplus
}
#endif

#endif


