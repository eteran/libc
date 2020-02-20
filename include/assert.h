/* C89, C94, C99 Compliant */

#ifndef _ASSERT_H_20051228_
#define _ASSERT_H_20051228_

#include "c/c-config.h"

_LIBC_BEGIN

_Noreturn void __assert_fail(const char *expr, const char *file, unsigned int line, const char *func) _NOEXCEPT;

#if defined(NDEBUG)
#define assert(ignore) ((void)0)
#else
#if defined(_HAS_C99) || defined(_HAS_CXX11)
#define assert(test) (!(test)) ? __assert_fail(#test, __FILE__, __LINE__, __func__) : (void)0
#else
#define assert(test) (!(test)) ? __assert_fail(#test, __FILE__, __LINE__, 0) : (void)0
#endif
#endif

#ifdef _HAS_C11
#define static_assert(expr, error) _Static_assert((expr), error)
#endif

_LIBC_END

#endif
