#undef NDEBUG
#define _ELIBC_SOURCE
#include "test_util.h"
#include <assert.h>
#include <stdint.h>

#define __STDC_LIMIT_MACROS

int main(void) {
	TYPE_DEFINED(int8_t);
	TYPE_DEFINED(int16_t);
	TYPE_DEFINED(int32_t);
	TYPE_DEFINED(int64_t);
	TYPE_DEFINED(uint8_t);
	TYPE_DEFINED(uint16_t);
	TYPE_DEFINED(uint32_t);
	TYPE_DEFINED(uint64_t);

	TYPE_DEFINED(int_least8_t);
	TYPE_DEFINED(int_least16_t);
	TYPE_DEFINED(int_least32_t);
	TYPE_DEFINED(int_least64_t);
	TYPE_DEFINED(uint_least8_t);
	TYPE_DEFINED(uint_least16_t);
	TYPE_DEFINED(uint_least32_t);
	TYPE_DEFINED(uint_least64_t);

	TYPE_DEFINED(int_fast8_t);
	TYPE_DEFINED(int_fast16_t);
	TYPE_DEFINED(int_fast32_t);
	TYPE_DEFINED(int_fast64_t);
	TYPE_DEFINED(uint_fast8_t);
	TYPE_DEFINED(uint_fast16_t);
	TYPE_DEFINED(uint_fast32_t);
	TYPE_DEFINED(uint_fast64_t);

	TYPE_DEFINED(intptr_t);
	TYPE_DEFINED(uintptr_t);
	TYPE_DEFINED(intmax_t);
	TYPE_DEFINED(uintmax_t);

#if defined(_HAS_C99)

#ifndef INT8_MIN
#error "INT8_MIN not defined"
#endif

#ifndef INT16_MIN
#error "INT16_MIN not defined"
#endif

#ifndef INT32_MIN
#error "INT32_MIN not defined"
#endif

#ifndef INT64_MIN
#error "INT64_MIN not defined"
#endif

#ifndef INT_FAST8_MIN
#error "INT_FAST8_MIN not defined"
#endif

#ifndef INT_FAST16_MIN
#error "INT_FAST16_MIN not defined"
#endif

#ifndef INT_FAST32_MIN
#error "INT_FAST32_MIN not defined"
#endif

#ifndef INT_FAST64_MIN
#error "INT_FAST64_MIN not defined"
#endif

#ifndef INT_LEAST8_MIN
#error "INT_LEAST8_MIN not defined"
#endif

#ifndef INT_LEAST16_MIN
#error "INT_LEAST16_MIN not defined"
#endif

#ifndef INT_LEAST32_MIN
#error "INT_LEAST32_MIN not defined"
#endif

#ifndef INT_LEAST64_MIN
#error "INT_LEAST64_MIN not defined"
#endif

#ifndef INTPTR_MIN
#error "INTPTR_MIN not defined"
#endif

#ifndef INTMAX_MIN
#error "INTMAX_MIN not defined"
#endif

/* Signed integers : maximum value */
#ifndef INT8_MAX
#error "INT8_MAX not defined"
#endif

#ifndef INT16_MAX
#error "INT16_MAX not defined"
#endif

#ifndef INT32_MAX
#error "INT32_MAX not defined"
#endif

#ifndef INT64_MAX
#error "INT64_MAX not defined"
#endif

#ifndef INT_FAST8_MAX
#error "INT_FAST8_MAX not defined"
#endif

#ifndef INT_FAST16_MAX
#error "INT_FAST16_MAX not defined"
#endif

#ifndef INT_FAST32_MAX
#error "INT_FAST32_MAX not defined"
#endif

#ifndef INT_FAST64_MAX
#error "INT_FAST64_MAX not defined"
#endif

#ifndef INT_LEAST8_MAX
#error "INT_LEAST8_MAX not defined"
#endif

#ifndef INT_LEAST16_MAX
#error "INT_LEAST16_MAX not defined"
#endif

#ifndef INT_LEAST32_MAX
#error "INT_LEAST32_MAX not defined"
#endif

#ifndef INT_LEAST64_MAX
#error "INT_LEAST64_MAX not defined"
#endif

#ifndef INTPTR_MAX
#error "INTPTR_MAX not defined"
#endif

#ifndef INTMAX_MAX
#error "INTMAX_MAX not defined"
#endif

/* Unsigned integers : maximum value*/
#ifndef UINT8_MAX
#error "UINT8_MAX not defined"
#endif

#ifndef UINT16_MAX
#error "UINT16_MAX not defined"
#endif

#ifndef UINT32_MAX
#error "UINT32_MAX not defined"
#endif

#ifndef UINT64_MAX
#error "UINT64_MAX not defined"
#endif

#ifndef UINT_FAST8_MAX
#error "UINT_FAST8_MAX not defined"
#endif

#ifndef UINT_FAST16_MAX
#error "UINT_FAST16_MAX not defined"
#endif

#ifndef UINT_FAST32_MAX
#error "UINT_FAST32_MAX not defined"
#endif

#ifndef UINT_FAST64_MAX
#error "UINT_FAST64_MAX not defined"
#endif

#ifndef UINT_LEAST8_MAX
#error "UINT_LEAST8_MAX not defined"
#endif

#ifndef UINT_LEAST16_MAX
#error "UINT_LEAST16_MAX not defined"
#endif

#ifndef UINT_LEAST32_MAX
#error "UINT_LEAST32_MAX not defined"
#endif

#ifndef UINT_LEAST64_MAX
#error "UINT_LEAST64_MAX not defined"
#endif

#ifndef UINTPTR_MAX
#error "UINTPTR_MAX not defined"
#endif

#ifndef UINTMAX_MAX
#error "UINTMAX_MAX not defined"
#endif

/* Other */
#ifndef PTRDIFF_MIN
#error "PTRDIFF_MIN not defined"
#endif

#ifndef PTRDIFF_MAX
#error "PTRDIFF_MAX not defined"
#endif

#ifndef SIG_ATOMIC_MIN
#error "SIG_ATOMIC_MIN not defined"
#endif

#ifndef SIG_ATOMIC_MAX
#error "SIG_ATOMIC_MAX not defined"
#endif

#ifndef SIZE_MAX
#error "SIZE_MAX not defined"
#endif

#ifndef WCHAR_MAX
#error "WCHAR_MAX not defined"
#endif

#ifndef WCHAR_MIN
#error "WCHAR_MIN not defined"
#endif

#ifndef WINT_MIN
#error "WINT_MIN not defined"
#endif

#ifndef WINT_MAX
#error "WINT_MAX not defined"
#endif

#endif

#if defined(_HAS_C99)

#ifndef INT8_C
#error "INT8_C not defined"
#endif

#ifndef INT16_C
#error "INT16_C not defined"
#endif

#ifndef INT32_C
#error "INT32_C not defined"
#endif

#ifndef INT64_C
#error "INT64_C not defined"
#endif

#ifndef UINT8_C
#error "UINT8_C not defined"
#endif

#ifndef UINT16_C
#error "UINT16_C not defined"
#endif

#ifndef UINT32_C
#error "UINT32_C not defined"
#endif

#ifndef UINT64_C
#error "UINT64_C not defined"
#endif

#ifndef INTMAX_C
#error "INTMAX_C not defined"
#endif

#ifndef UINTMAX_C
#error "UINTMAX_C not defined"
#endif

#endif
	return 0;
}
