/* C89, C94, C99 Compliant */

#ifndef _ASSERT_H_20051228_
#define _ASSERT_H_20051228_

#include "c/c-config.h"

_LIBC_BEGIN

#define __ELIBC_STRINGIFY(x) #x
#define __ELIBC_TOSTRING(x)  __ELIBC_STRINGIFY(x)

_Noreturn void __assert_fail(const char *expr, const char *file, const char *line,
							 const char *func) _NOEXCEPT;

#if defined(NDEBUG)
#define assert(test) _ASSUME(!!(test))
#else

#if defined(_HAS_C99) || defined(_HAS_CXX11)
#define assert(test) \
	(!(test)) ? __assert_fail(#test, __FILE__, __ELIBC_TOSTRING(__LINE__), __func__) : (void)0
#else
#define assert(test) \
	(!(test)) ? __assert_fail(#test, __FILE__, __ELIBC_TOSTRING(__LINE__), 0) : (void)0
#endif

#endif

#if defined(_HAS_C11) && !defined(_HAS_CXX11)
#define static_assert(expr, error) _Static_assert((expr), error)
#endif

_LIBC_END

#endif
