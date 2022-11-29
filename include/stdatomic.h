/* C89, C94, C99 Compliant */

#ifndef _STDATOMIC_H_20130922_
#define _STDATOMIC_H_20130922_

#include "c/c-config.h"

#include "c/_c11_warning.h"
#include <stddef.h>
#include <stdint.h>
#include <uchar.h>
#include <wchar.h>

#if defined(_HAS_C11) || defined(_HAS_CXX11)

#ifndef __STDC_NO_ATOMICS__

#define ATOMIC_BOOL_LOCK_FREE     2
#define ATOMIC_CHAR_LOCK_FREE     2
#define ATOMIC_CHAR16_T_LOCK_FREE 2
#define ATOMIC_CHAR32_T_LOCK_FREE 2
#define ATOMIC_WCHAR_T_LOCK_FREE  2
#define ATOMIC_SHORT_LOCK_FREE    2
#define ATOMIC_INT_LOCK_FREE      2
#define ATOMIC_LONG_LOCK_FREE     2
#define ATOMIC_LLONG_LOCK_FREE    2
#define ATOMIC_POINTER_LOCK_FREE  2

#ifdef _HAS_C23
#define ATOMIC_CHAR8_T_LOCK_FREE 2
#endif

#define ATOMIC_FLAG_INIT \
	{ 0 }

#ifndef _HAS_C23
/* NOTE(eteran): deprecated in C17 */
#define ATOMIC_VAR_INIT(value) /* unspecified */
#endif

/* TODO(eteran): what do we need to do here? */
#define kill_dependency(y) (y)

typedef _Atomic(_Bool) atomic_bool;
typedef _Atomic(char) atomic_char;
typedef _Atomic(signed char) atomic_schar;
typedef _Atomic(unsigned char) atomic_uchar;
typedef _Atomic(short) atomic_short;
typedef _Atomic(unsigned short) atomic_ushort;
typedef _Atomic(int) atomic_int;
typedef _Atomic(unsigned int) atomic_uint;
typedef _Atomic(long) atomic_long;
typedef _Atomic(unsigned long) atomic_ulong;
typedef _Atomic(long long) atomic_llong;
typedef _Atomic(unsigned long long) atomic_ullong;
typedef _Atomic(char16_t) atomic_char16_t;
typedef _Atomic(char32_t) atomic_char32_t;
typedef _Atomic(wchar_t) atomic_wchar_t;
typedef _Atomic(int_least8_t) atomic_int_least8_t;
typedef _Atomic(uint_least8_t) atomic_uint_least8_t;
typedef _Atomic(int_least16_t) atomic_int_least16_t;
typedef _Atomic(uint_least16_t) atomic_uint_least16_t;
typedef _Atomic(int_least32_t) atomic_int_least32_t;
typedef _Atomic(uint_least32_t) atomic_uint_least32_t;
typedef _Atomic(int_least64_t) atomic_int_least64_t;
typedef _Atomic(uint_least64_t) atomic_uint_least64_t;
typedef _Atomic(int_fast8_t) atomic_int_fast8_t;
typedef _Atomic(uint_fast8_t) atomic_uint_fast8_t;
typedef _Atomic(int_fast16_t) atomic_int_fast16_t;
typedef _Atomic(uint_fast16_t) atomic_uint_fast16_t;
typedef _Atomic(int_fast32_t) atomic_int_fast32_t;
typedef _Atomic(uint_fast32_t) atomic_uint_fast32_t;
typedef _Atomic(int_fast64_t) atomic_int_fast64_t;
typedef _Atomic(uint_fast64_t) atomic_uint_fast64_t;
typedef _Atomic(intptr_t) atomic_intptr_t;
typedef _Atomic(uintptr_t) atomic_uintptr_t;
typedef _Atomic(size_t) atomic_size_t;
typedef _Atomic(ptrdiff_t) atomic_ptrdiff_t;
typedef _Atomic(intmax_t) atomic_intmax_t;
typedef _Atomic(uintmax_t) atomic_uintmax_t;
#endif

enum memory_order {
	memory_order_relaxed = __ATOMIC_RELAXED,
	memory_order_consume = __ATOMIC_CONSUME,
	memory_order_acquire = __ATOMIC_ACQUIRE,
	memory_order_release = __ATOMIC_RELEASE,
	memory_order_acq_rel = __ATOMIC_ACQ_REL,
	memory_order_seq_cst = __ATOMIC_SEQ_CST
};

#define _Memory_order_mask          0x0ffff
#define _Memory_order_modifier_mask 0xffff0000
#define _Memory_order_hle_acquire   0x10000
#define _Memory_order_hle_release   0x20000

struct atomic_flag {
	int value;
};

_Bool atomic_flag_test_and_set_explicit(volatile struct atomic_flag *obj, enum memory_order order) {
	return __atomic_test_and_set(&obj->value, order);
}

_Bool atomic_flag_test_and_set(volatile struct atomic_flag *obj) {
	return atomic_flag_test_and_set_explicit(obj, memory_order_seq_cst);
}

void atomic_flag_clear_explicit(volatile struct atomic_flag *obj, enum memory_order order) {
	const enum memory_order m = order & _Memory_order_mask;
	assert(m != memory_order_consume);
	assert(m != memory_order_acquire);
	assert(m != memory_order_acq_rel);
	__atomic_clear(&obj->value, order);
}

void atomic_flag_clear(volatile struct atomic_flag *obj) {
	atomic_flag_clear_explicit(obj, memory_order_seq_cst);
}

#if 0
void atomic_init(volatile A *obj, C desired);
_Bool atomic_is_lock_free(const volatile A *obj);
void atomic_store(volatile A *obj, C desired);
void atomic_store_explicit(volatile A *obj, C desired, enum memory_order order);
C atomic_load(const volatile A *obj);
C atomic_load_explicit(const volatile A *obj, enum memory_order order);
C atomic_exchange(volatile A *obj, C desired);
C atomic_exchange_explicit(volatile A *obj, C desired, enum memory_order order);
_Bool atomic_compare_exchange_strong(volatile A *obj, C *expected, C desired);
_Bool atomic_compare_exchange_weak(volatile A *obj, C *expected, C desired);
_Bool atomic_compare_exchange_strong_explicit(volatile A *obj, C *expected, C desired, enum memory_order succ, enum memory_order fail);
_Bool atomic_compare_exchange_weak_explicit(volatile A *obj, C *expected, C desired, enum memory_order succ, enum memory_order fail);
C atomic_fetch_add(volatile A *obj, M arg);
C atomic_fetch_add_explicit(volatile A *obj, M arg, enum memory_order order);
C atomic_fetch_sub(volatile A *obj, M arg);
C atomic_fetch_sub_explicit(volatile A *obj, M arg, enum memory_order order);
C atomic_fetch_or(volatile A *obj, M arg);
C atomic_fetch_or_explicit(volatile A *obj, M arg, enum memory_order order);
C atomic_fetch_xor(volatile A *obj, M arg);
C atomic_fetch_xor_explicit(volatile A *obj, M arg, enum memory_order order);
C atomic_fetch_and(volatile A *obj, M arg);
C atomic_fetch_and_explicit(volatile A *obj, M arg, enum memory_order order);
void atomic_thread_fence(enum memory_order order);
void atomic_signal_fence(enum memory_order order);
#endif

#endif

#endif
