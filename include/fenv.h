/* C89, C94, C99 Compliant */

#ifndef _FENV_H_04012009_
#define _FENV_H_04012009_

#include "c/c-config.h"

#include "c/_c99_warning.h"

#include "arch_fenv_t.h"
#include "arch_fexcept_t.h"

#define FE_INVALID 0x0001
#define FE_DENORMAL 0x0002 /* extension, x86/x86-64 only so far */
#define FE_DIVBYZERO 0x0004
#define FE_OVERFLOW 0x0008
#define FE_UNDERFLOW 0x0010
#define FE_INEXACT 0x0020

#define FE_ALL_EXCEPT (FE_INVALID | FE_DENORMAL | FE_DIVBYZERO | FE_OVERFLOW | FE_UNDERFLOW | FE_INEXACT)

/*
 * rounding control:
 * 00 = Round to nearest whole number. (default)
 * 01 = Round down, toward -infinity.
 * 10 = Round up, toward +infinity.
 * 11 = Round toward zero (truncate).
 */

#define FE_TONEAREST 0x0000
#define FE_DOWNWARD 0x0400
#define FE_UPWARD 0x0800
#define FE_TOWARDZERO 0x0c00

#define __ELIBC_FE_ROUND_MASK (FE_TONEAREST | FE_DOWNWARD | FE_UPWARD | FE_TOWARDZERO)

#define FE_DFL_ENV ((const fenv_t *)-1)

#include "c/feclearexcept.h"
#include "c/fegetenv.h"
#include "c/fegetexceptflag.h"
#include "c/fegetround.h"
#include "c/feraiseexcept.h"
#include "c/fesetenv.h"
#include "c/fesetexceptflag.h"
#include "c/fesetround.h"
#include "c/fetestexcept.h"
#include "c/feupdateenv.h"

/* #pragma STDC FENV_ACCESS on */

#endif
