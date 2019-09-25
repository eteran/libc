/* C89, C94, C99 Compliant */

#ifndef MATH_20051228_H_
#define MATH_20051228_H_

#include "c/c-config.h"

#if defined(__GNUC__)
#define __ELIBC_HUGE_VALUE  __builtin_huge_val()
#define __ELIBC_HUGE_VALUEF __builtin_huge_valf()
#define __ELIBC_HUGE_VALUEL __builtin_huge_vall()
#define __ELIBC_INF         __builtin_inf()
#define __ELIBC_NAN(x)      __builtin_nan(x)
#else
#error "no support for nan/inf/huge_value with this compiler"
#endif

#define HUGE_VAL __ELIBC_HUGE_VALUE

#include "c/acos.h"
#include "c/asin.h"
#include "c/atan.h"
#include "c/atan2.h"
#include "c/cos.h"
#include "c/sin.h"
#include "c/tan.h"
#include "c/cosh.h"
#include "c/sinh.h"
#include "c/tanh.h"
#include "c/exp.h"
#include "c/frexp.h"
#include "c/ldexp.h"
#include "c/log.h"
#include "c/log10.h"
#include "c/modf.h"
#include "c/pow.h"
#include "c/sqrt.h"
#include "c/ceil.h"
#include "c/fabs.h"
#include "c/floor.h"
#include "c/fmod.h"

#if defined(_HAS_C99) || defined(__ELIBC_SOURCE)

/*
#pragma STDC FP_CONTRACT on-off-switch
*/

#include "c/acosf.h"
#include "c/acoshf.h"
#include "c/acoshl.h"
#include "c/acosl.h"
#include "c/asinf.h"
#include "c/asinhf.h"
#include "c/asinhl.h"
#include "c/asinl.h"
#include "c/atan2f.h"
#include "c/atan2l.h"
#include "c/atanf.h"
#include "c/atanhf.h"
#include "c/atanhl.h"
#include "c/atanl.h"
#include "c/cbrtf.h"
#include "c/cbrtl.h"
#include "c/ceilf.h"
#include "c/ceill.h"
#include "c/copysignf.h"
#include "c/copysignl.h"
#include "c/cosf.h"
#include "c/coshf.h"
#include "c/coshl.h"
#include "c/cosl.h"
#include "c/erf.h"
#include "c/erfcf.h"
#include "c/erfcl.h"
#include "c/erff.h"
#include "c/erfl.h"
#include "c/exp2f.h"
#include "c/exp2l.h"
#include "c/expf.h"
#include "c/expl.h"
#include "c/expm1f.h"
#include "c/expm1l.h"
#include "c/fabsf.h"
#include "c/fabsl.h"
#include "c/fdimf.h"
#include "c/fdiml.h"
#include "c/floorf.h"
#include "c/floorl.h"
#include "c/fmaf.h"
#include "c/fmal.h"
#include "c/fmaxf.h"
#include "c/fmaxl.h"
#include "c/fminf.h"
#include "c/fminl.h"
#include "c/fmodf.h"
#include "c/fmodl.h"
#include "c/frexpf.h"
#include "c/frexpl.h"
#include "c/hypotf.h"
#include "c/hypotl.h"
#include "c/ilogbf.h"
#include "c/ilogbl.h"
#include "c/ldexpf.h"
#include "c/ldexpl.h"
#include "c/lgammaf.h"
#include "c/lgammal.h"
#include "c/llrintf.h"
#include "c/llrintl.h"
#include "c/llroundf.h"
#include "c/llroundl.h"
#include "c/log10f.h"
#include "c/log10l.h"
#include "c/log1pf.h"
#include "c/log1pl.h"
#include "c/log2f.h"
#include "c/log2l.h"
#include "c/logbf.h"
#include "c/logbl.h"
#include "c/logf.h"
#include "c/logl.h"
#include "c/lrintf.h"
#include "c/lrintl.h"
#include "c/lroundf.h"
#include "c/lroundl.h"
#include "c/modff.h"
#include "c/modfl.h"
#include "c/nanf.h"
#include "c/nanl.h"
#include "c/nearbyintf.h"
#include "c/nearbyintl.h"
#include "c/nextafterf.h"
#include "c/nextafterl.h"
#include "c/nexttowardf.h"
#include "c/nexttowardl.h"
#include "c/powf.h"
#include "c/powl.h"
#include "c/remainderf.h"
#include "c/remainderl.h"
#include "c/remquof.h"
#include "c/remquol.h"
#include "c/rintf.h"
#include "c/rintl.h"
#include "c/roundf.h"
#include "c/roundl.h"
#include "c/scalblnf.h"
#include "c/scalblnl.h"
#include "c/scalbnf.h"
#include "c/scalbnl.h"
#include "c/sinf.h"
#include "c/sinhf.h"
#include "c/sinhl.h"
#include "c/sinl.h"
#include "c/sqrtf.h"
#include "c/sqrtl.h"
#include "c/tanf.h"
#include "c/tanhf.h"
#include "c/tanhl.h"
#include "c/tanl.h"
#include "c/tgammaf.h"
#include "c/tgammal.h"
#include "c/truncf.h"
#include "c/truncl.h"
#endif

#if defined(_HAS_C99) || defined(_HAS_CXX11) || defined(__ELIBC_SOURCE)

/* TODO(eteran): should we make these depend on FLT_EVAL_METHOD directly ? */
typedef double double_t;
typedef float  float_t;

#define FP_ILOGBNAN (-1-(int)(((unsigned)-1)>>1))
#define FP_ILOGB0   FP_ILOGBNAN

#define INFINITY  __ELIBC_INF
#define NAN       __ELIBC_NAN("")

#define HUGE_VALF __ELIBC_HUGE_VALUEF
#define HUGE_VALL __ELIBC_HUGE_VALUEL

#define FP_NAN       0
#define FP_INFINITE  1
#define FP_ZERO      2
#define FP_SUBNORMAL 3
#define FP_NORMAL    4

/* NOTE: our FMA[LF} may or may not be "fast", so not defined for now */
/* FP_FAST_FMA */
/* FP_FAST_FMAF */
/* FP_FAST_FMAL */

#define MATH_ERRNO       1
#define MATH_ERREXCEPT   2
#define math_errhandling 2 /* TODO(eteran): is this true? */

#include "c/acosh.h"
#include "c/asinh.h"
#include "c/atanh.h"
#include "c/cbrt.h"
#include "c/copysign.h"
#include "c/erfc.h"
#include "c/exp2.h"
#include "c/expm1.h"
#include "c/fdim.h"
#include "c/fma.h"
#include "c/fmax.h"
#include "c/fmin.h"
#include "c/fpclassify.h"
#include "c/hypot.h"
#include "c/ilogb.h"
#include "c/isfinite.h"
#include "c/isgreater.h"
#include "c/isgreaterequal.h"
#include "c/isinf.h"
#include "c/isless.h"
#include "c/islessequal.h"
#include "c/islessgreater.h"
#include "c/isnan.h"
#include "c/isnormal.h"
#include "c/isunordered.h"
#include "c/lgamma.h"
#include "c/llrint.h"
#include "c/llround.h"
#include "c/log1p.h"
#include "c/log2.h"
#include "c/logb.h"
#include "c/lrint.h"
#include "c/lround.h"
#include "c/nan.h"
#include "c/nearbyint.h"
#include "c/nextafter.h"
#include "c/nexttoward.h"
#include "c/remainder.h"
#include "c/remquo.h"
#include "c/rint.h"
#include "c/round.h"
#include "c/scalbln.h"
#include "c/scalbn.h"
#include "c/signbit.h"
#include "c/tgamma.h"
#include "c/trunc.h"
#endif

/* POSIX */
#define M_PI 3.14159265358979323846
#define M_E  2.7182818284590452354

#endif
