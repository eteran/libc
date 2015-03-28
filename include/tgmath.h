/* C89, C94, C99 Compliant */

#ifndef TGMATH_20090402_H_
#define TGMATH_20090402_H_

#include "c/c-config.h"
#include "c/_c99_warning.h"
#include <math.h>
#include <complex.h>

/* this macro does all the magic and would need to be updated if we want
 * to support imaginary types as well. Currently, if you pass
 * an unknown type, we simply result in a void expression 
 * causing a compiler error
 */


#if defined(__STDC_NO_COMPLEX__)

#define __ELIBC_TGCALL(x, func) \
	__builtin_choose_expr(                                                        \
		__builtin_types_compatible_p(__typeof__(x), long double), (func ## l)(x), \
	__builtin_choose_expr(                                                        \
		__builtin_types_compatible_p(__typeof__(x), float), (func ## f)(x),       \
	__builtin_choose_expr(                                                        \
		__builtin_types_compatible_p(__typeof__(x), double), (func)(x),           \
	(void)0)))

#else

#define __ELIBC_TGCALL(x, func) \
	__builtin_choose_expr(                                                                      \
		__builtin_types_compatible_p(__typeof__(x), long double), (func ## l)(x),               \
	__builtin_choose_expr(                                                                      \
		__builtin_types_compatible_p(__typeof__(x), float), (func ## f)(x),                     \
	__builtin_choose_expr(                                                                      \
		__builtin_types_compatible_p(__typeof__(x), double), (func)(x),                         \
	__builtin_choose_expr(                                                                      \
		__builtin_types_compatible_p(__typeof__(x), long double _Complex), (c ## func ## l)(x), \
	__builtin_choose_expr(                                                                      \
		__builtin_types_compatible_p(__typeof__(x), float _Complex), (c ## func ## f)(x),       \
	__builtin_choose_expr(                                                                      \
		__builtin_types_compatible_p(__typeof__(x), double _Complex), (c ## func)(x),           \
	(void)0))))))

#endif

#define acos(x)        __ELIBC_TGCALL((x), acos)
#define asin(x)        __ELIBC_TGCALL((x), asin)
#define atan(x)        __ELIBC_TGCALL((x), atan)
#define acosh(x)       __ELIBC_TGCALL((x), acosh)
#define asinh(x)       __ELIBC_TGCALL((x), asinh)
#define atanh(x)       __ELIBC_TGCALL((x), atanh)
#define cos(x)         __ELIBC_TGCALL((x), cos)
#define sin(x)         __ELIBC_TGCALL((x), sin)
#define tan(x)         __ELIBC_TGCALL((x), tan)
#define cosh(x)        __ELIBC_TGCALL((x), cosh)
#define sinh(x)        __ELIBC_TGCALL((x), sinh)
#define tanh(x)        __ELIBC_TGCALL((x), tanh)
#define exp(x)         __ELIBC_TGCALL((x), exp)
#define log(x)         __ELIBC_TGCALL((x), log)
#define sqrt(x)        __ELIBC_TGCALL((x), sqrt)
#define fabs(x)        __ELIBC_TGCALL((x), fabs)
#define cbrt(x)        __ELIBC_TGCALL((x), cbrt)
#define ceil(x)        __ELIBC_TGCALL((x), ceil)
#define erf(x)         __ELIBC_TGCALL((x), erf)
#define erfc(x)        __ELIBC_TGCALL((x), erfc)
#define exp2(x)        __ELIBC_TGCALL((x), exp2)
#define expm1(x)       __ELIBC_TGCALL((x), expm1)
#define floor(x)       __ELIBC_TGCALL((x), floor)
#define frexp(x)       __ELIBC_TGCALL((x), frexp)
#define ilogb(x)       __ELIBC_TGCALL((x), ilogb)
#define ldexp(x)       __ELIBC_TGCALL((x), ldexp)
#define lgamma(x)      __ELIBC_TGCALL((x), lgamma)
#define llrint(x)      __ELIBC_TGCALL((x), llrint)
#define llround(x)     __ELIBC_TGCALL((x), llround)
#define log10(x)       __ELIBC_TGCALL((x), log10)
#define log1p(x)       __ELIBC_TGCALL((x), log1p)
#define log2(x)        __ELIBC_TGCALL((x), log2)
#define logb(x)        __ELIBC_TGCALL((x), logb)
#define lrint(x)       __ELIBC_TGCALL((x), lrint)
#define lround(x)      __ELIBC_TGCALL((x), lround)
#define nearbyint(x)   __ELIBC_TGCALL((x), nearbyint)
#define rint(x)        __ELIBC_TGCALL((x), rint)
#define round(x)       __ELIBC_TGCALL((x), round)
#define tgamma(x)      __ELIBC_TGCALL((x), tgamma)
#define trunc(x)       __ELIBC_TGCALL((x), trunc)
#define carg(x)        __ELIBC_TGCALL((x), carg)
#define cimag(x)       __ELIBC_TGCALL((x), cimag)
#define conj(x)        __ELIBC_TGCALL((x), conj)
#define cproj(x)       __ELIBC_TGCALL((x), cproj)
#define creal(x)       __ELIBC_TGCALL((x), creal)



/* TODO: how do we account for the type of y? */
#if defined(__STDC_NO_COMPLEX__)
#define __ELIBC_TGCALL2(x, y, func) \
	__builtin_choose_expr(                                                        \
		__builtin_types_compatible_p(__typeof__(x), long double), (func ## l)((x), (y)), \
	__builtin_choose_expr(                                                        \
		__builtin_types_compatible_p(__typeof__(x), float), (func ## f)((x), (y)),       \
	__builtin_choose_expr(                                                        \
		__builtin_types_compatible_p(__typeof__(x), double), (func)((x), (y)),           \
	(void)0)))

#else
#define __ELIBC_TGCALL2(x, y, func) \
	__builtin_choose_expr(                                                                             \
		__builtin_types_compatible_p(__typeof__(x), long double), (func ## l)((x), (y)),               \
	__builtin_choose_expr(                                                                             \
		__builtin_types_compatible_p(__typeof__(x), float), (func ## f)((x), (y)),                     \
	__builtin_choose_expr(                                                                             \
		__builtin_types_compatible_p(__typeof__(x), double), (func)((x), (y)),                         \
	__builtin_choose_expr(                                                                             \
		__builtin_types_compatible_p(__typeof__(x), long double _Complex), (c ## func ## l)((x), (y)), \
	__builtin_choose_expr(                                                                             \
		__builtin_types_compatible_p(__typeof__(x), float _Complex), (c ## func ## f)((x), (y)),       \
	__builtin_choose_expr(                                                                             \
		__builtin_types_compatible_p(__typeof__(x), double _Complex), (c ## func)((x), (y)),           \
	(void)0))))))
#endif

#define atan2(x, y)       __ELIBC_TGCALL2((x), (y), atan2)
#define fmod(x, y)        __ELIBC_TGCALL2((x), (y), fmod)
#define modf(x, y)        __ELIBC_TGCALL2((x), (y), modf)
#define pow(x, y)         __ELIBC_TGCALL2((x), (y), pow)
#define copysign(x, y)    __ELIBC_TGCALL2((x), (y), copysign)	
#define fdim(x, y)        __ELIBC_TGCALL2((x), (y), fdim)
#define fmax(x, y)        __ELIBC_TGCALL2((x), (y), fmax)
#define fmin(x, y)        __ELIBC_TGCALL2((x), (y), fmin)
#define hypot(x, y)       __ELIBC_TGCALL2((x), (y), hypot)
#define nextafter(x, y)   __ELIBC_TGCALL2((x), (y), nextafter)
#define nexttowards(x, y) __ELIBC_TGCALL2((x), (y), nexttowards)
#define remainder(x, y)   __ELIBC_TGCALL2((x), (y), remainder)
#define scalbn(x, y)      __ELIBC_TGCALL2((x), (y), scalbn)
#define scalbln(x, y)     __ELIBC_TGCALL2((x), (y), scalbln)


/* TODO: how do we account for the type of y and z? */
#if defined(__STDC_NO_COMPLEX__)
#define __ELIBC_TGCALL3(x, y, z, func) \
	__builtin_choose_expr(                                                                    \
		__builtin_types_compatible_p(__typeof__(x), long double), (func ## l)((x), (y), (z)), \
	__builtin_choose_expr(                                                                    \
		__builtin_types_compatible_p(__typeof__(x), float), (func ## f)((x), (y), (z)),       \
	__builtin_choose_expr(                                                                    \
		__builtin_types_compatible_p(__typeof__(x), double), (func)((x), (y), (z)),           \
	(void)0)))

#else
#define __ELIBC_TGCALL3(x, y, z, func) \
	__builtin_choose_expr(                                                                                  \
		__builtin_types_compatible_p(__typeof__(x), long double), (func ## l)((x), (y), (z)),               \
	__builtin_choose_expr(                                                                                  \
		__builtin_types_compatible_p(__typeof__(x), float), (func ## f)((x), (y), (z)),                     \
	__builtin_choose_expr(                                                                                  \
		__builtin_types_compatible_p(__typeof__(x), double), (func)((x), (y), (z)),                         \
	__builtin_choose_expr(                                                                                  \
		__builtin_types_compatible_p(__typeof__(x), long double _Complex), (c ## func ## l)((x), (y), (z)), \
	__builtin_choose_expr(                                                                                  \
		__builtin_types_compatible_p(__typeof__(x), float _Complex), (c ## func ## f)((x), (y), (z)),       \
	__builtin_choose_expr(                                                                                  \
		__builtin_types_compatible_p(__typeof__(x), double _Complex), (c ## func)((x), (y), (z)),           \
	(void)0))))))
#endif

#define remquo(x, y, z)      __ELIBC_TGCALL3((x), (y), (z), remquo)
#define fma(x, y, z)         __ELIBC_TGCALL3((x), (y), (z), fma)




#endif
