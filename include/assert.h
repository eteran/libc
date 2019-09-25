/* C89, C94, C99 Compliant */

#ifndef ASSERT_20051228_H_
#define ASSERT_20051228_H_

#include "c/c-config.h"

#ifdef __cplusplus
extern "C" {
#endif

_Noreturn void __assert_fail(const char *expr, const char *file, unsigned int line, const char *func) _NOEXCEPT;

#if defined(NDEBUG)
	#define assert(ignore)   ((void)0)
#else
	#if defined(_HAS_C99) || defined(_HAS_CXX11)
		#define assert(test) (!(test)) ? __assert_fail(# test, __FILE__, __LINE__, __func__) : (void)0
	#else
		#define assert(test) (!(test)) ? __assert_fail(# test, __FILE__, __LINE__, 0       ) : (void)0
	#endif
#endif

#ifdef _HAS_C11
#define static_assert(expr, error) _Static_assert((expr), error)
#endif

#ifdef __cplusplus
}
#endif

#endif
