/* C89, C94, C99 Compliant */

#ifndef _TGMATH_H_20090402_
#define _TGMATH_H_20090402_

#include "c/c-config.h"

#include "c/_c99_warning.h"

#include <complex.h>
#include <math.h>

/* this macro does all the magic and would need to be updated if we want
 * to support imaginary types as well.
 */

#if defined(__STDC_NO_COMPLEX__)

/* clang-format off */
#define _ELIBC_TGCALL(x, func) \
	__builtin_choose_expr(__builtin_types_compatible_p(__typeof__(x), long double), (func ## l)(x), \
	__builtin_choose_expr(__builtin_types_compatible_p(__typeof__(x), double),      (func)(x),      \
	__builtin_choose_expr(__builtin_types_compatible_p(__typeof__(x), float),       (func ## f)(x), \
	(func)(x)                                                                                       \
	)))
/* clang-format on */

#else
#error "Complex Is Not Implemented"
#endif

#define acos(x)      _ELIBC_TGCALL((x), acos)
#define asin(x)      _ELIBC_TGCALL((x), asin)
#define atan(x)      _ELIBC_TGCALL((x), atan)
#define acosh(x)     _ELIBC_TGCALL((x), acosh)
#define asinh(x)     _ELIBC_TGCALL((x), asinh)
#define atanh(x)     _ELIBC_TGCALL((x), atanh)
#define cos(x)       _ELIBC_TGCALL((x), cos)
#define sin(x)       _ELIBC_TGCALL((x), sin)
#define tan(x)       _ELIBC_TGCALL((x), tan)
#define cosh(x)      _ELIBC_TGCALL((x), cosh)
#define sinh(x)      _ELIBC_TGCALL((x), sinh)
#define tanh(x)      _ELIBC_TGCALL((x), tanh)
#define exp(x)       _ELIBC_TGCALL((x), exp)
#define log(x)       _ELIBC_TGCALL((x), log)
#define sqrt(x)      _ELIBC_TGCALL((x), sqrt)
#define fabs(x)      _ELIBC_TGCALL((x), fabs)
#define cbrt(x)      _ELIBC_TGCALL((x), cbrt)
#define ceil(x)      _ELIBC_TGCALL((x), ceil)
#define erf(x)       _ELIBC_TGCALL((x), erf)
#define erfc(x)      _ELIBC_TGCALL((x), erfc)
#define exp2(x)      _ELIBC_TGCALL((x), exp2)
#define expm1(x)     _ELIBC_TGCALL((x), expm1)
#define floor(x)     _ELIBC_TGCALL((x), floor)
#define frexp(x)     _ELIBC_TGCALL((x), frexp)
#define ilogb(x)     _ELIBC_TGCALL((x), ilogb)
#define lgamma(x)    _ELIBC_TGCALL((x), lgamma)
#define llrint(x)    _ELIBC_TGCALL((x), llrint)
#define llround(x)   _ELIBC_TGCALL((x), llround)
#define log10(x)     _ELIBC_TGCALL((x), log10)
#define log1p(x)     _ELIBC_TGCALL((x), log1p)
#define log2(x)      _ELIBC_TGCALL((x), log2)
#define logb(x)      _ELIBC_TGCALL((x), logb)
#define lrint(x)     _ELIBC_TGCALL((x), lrint)
#define lround(x)    _ELIBC_TGCALL((x), lround)
#define nearbyint(x) _ELIBC_TGCALL((x), nearbyint)
#define rint(x)      _ELIBC_TGCALL((x), rint)
#define round(x)     _ELIBC_TGCALL((x), round)
#define tgamma(x)    _ELIBC_TGCALL((x), tgamma)
#define trunc(x)     _ELIBC_TGCALL((x), trunc)
#define carg(x)      _ELIBC_TGCALL((x), carg)
#define cimag(x)     _ELIBC_TGCALL((x), cimag)
#define conj(x)      _ELIBC_TGCALL((x), conj)
#define cproj(x)     _ELIBC_TGCALL((x), cproj)
#define creal(x)     _ELIBC_TGCALL((x), creal)

#if defined(__STDC_NO_COMPLEX__)
/* clang-format off */
#define _ELIBC_TGCALL2(x, y, func) \
	__builtin_choose_expr(__builtin_types_compatible_p(__typeof__(x), long double), (func ## l)((x), (y)), \
	__builtin_choose_expr(__builtin_types_compatible_p(__typeof__(x), double),      (func)((x), (y)),      \
	__builtin_choose_expr(__builtin_types_compatible_p(__typeof__(x), float),       (func ## f)((x), (y)), \
	(func)((x), (y))                                                                                       \
	)))
/* clang-format on */
#else
#error "Complex Is Not Implemented"
#endif

#define atan2(x, y)      _ELIBC_TGCALL2((x), (y), atan2)
#define fmod(x, y)       _ELIBC_TGCALL2((x), (y), fmod)
#define modf(x, y)       _ELIBC_TGCALL2((x), (y), modf)
#define pow(x, y)        _ELIBC_TGCALL2((x), (y), pow)
#define copysign(x, y)   _ELIBC_TGCALL2((x), (y), copysign)
#define fdim(x, y)       _ELIBC_TGCALL2((x), (y), fdim)
#define fmax(x, y)       _ELIBC_TGCALL2((x), (y), fmax)
#define ldexp(x, y)      _ELIBC_TGCALL2((x), (y), ldexp)
#define fmin(x, y)       _ELIBC_TGCALL2((x), (y), fmin)
#define hypot(x, y)      _ELIBC_TGCALL2((x), (y), hypot)
#define nextafter(x, y)  _ELIBC_TGCALL2((x), (y), nextafter)
#define nexttoward(x, y) _ELIBC_TGCALL2((x), (y), nexttoward)
#define remainder(x, y)  _ELIBC_TGCALL2((x), (y), remainder)
#define scalbn(x, y)     _ELIBC_TGCALL2((x), (y), scalbn)
#define scalbln(x, y)    _ELIBC_TGCALL2((x), (y), scalbln)

#if defined(__STDC_NO_COMPLEX__)
/* clang-format off */
#define _ELIBC_TGCALL3(x, y, z, func) \
	__builtin_choose_expr(__builtin_types_compatible_p(__typeof__(x), long double), (func ## l)((x), (y), (z)), \
	__builtin_choose_expr(__builtin_types_compatible_p(__typeof__(x), double),      (func)((x), (y), (z)),      \
	__builtin_choose_expr(__builtin_types_compatible_p(__typeof__(x), float),       (func ## f)((x), (y), (z)), \
	(func)((x), (y), (z))                                                                                       \
	)))
/* clang-format on */
#else
#error "Complex Is Not Implemented"
#endif

#define remquo(x, y, z) _ELIBC_TGCALL3((x), (y), (z), remquo)
#define fma(x, y, z)    _ELIBC_TGCALL3((x), (y), (z), fma)

#endif
