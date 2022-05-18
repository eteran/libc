
#ifndef _C_C_CONFIG_H_20051228_
#define _C_C_CONFIG_H_20051228_

/* C Version detection */
#ifdef __STDC_VERSION__
#if __STDC_VERSION__ >= 201112L
#define _HAS_C11
#endif

#if __STDC_VERSION__ >= 199901L
#define _HAS_C99
#endif

#if __STDC_VERSION__ >= 199409L
#define _HAS_C94
#endif

#define _HAS_C90
#endif

/* C++ Version detection */
#ifdef __cplusplus
#if __cplusplus >= 202002L
#define _HAS_CXX20
#endif

#if __cplusplus >= 201703L
#define _HAS_CXX17
#endif

#if __cplusplus >= 201402L
#define _HAS_CXX14
#endif

#if __cplusplus >= 201103L
#define _HAS_CXX11
#endif

#if __cplusplus >= 199711L
#define _HAS_CXX03
#define _HAS_CXX89
#endif
#endif

/* C++ header compatibility */
#ifdef __cplusplus
#define _LIBC_BEGIN extern "C" {
#define _LIBC_END   }
#else
#define _LIBC_BEGIN
#define _LIBC_END
#endif

/* floating point math supported */
#if (defined(__x86_64__) && (defined(__SSE2_MATH__) || defined(__SSE_MATH__))) || defined(__i386__)
#define _HAS_FPU
#endif

/* restrict keyword support */
#if defined(_HAS_C99)
#define _RESTRICT restrict
#elif defined(__GNUC__)
#define _RESTRICT __restrict
#else
#define _RESTRICT
#endif

#if defined(_HAS_CXX11)
#define _NOEXCEPT noexcept
#elif defined(_HAS_CXX89)
#define _NOEXCEPT throw()
#elif defined(__GNUC__)
#define _NOEXCEPT __attribute__((__nothrow__))
#else
#define _NOEXCEPT
#endif

#ifdef _HAS_CXX14
#define _DEPRECATED [[deprecated]]
#elif defined(__GNUC__)
#define _DEPRECATED __attribute__((deprecated))
#else
#define _DEPRECATED
#endif

#if defined(__GNUC__)
#define _INLINE        __inline__
#define _CONST         __attribute__((__const__))
#define _PURE          __attribute__((__pure__))
#define _ALWAYS_INLINE __attribute__((always_inline))
#else
#define _INLINE
#define _CONST
#define _PURE
#define _ALWAYS_INLINE
#endif

/* TODO(eteran): enable TLS */
#if !defined(_HAS_C11) && defined(__GNUC__) && !defined(__KERNEL__)
#define _Thread_local /*__thread*/
#else
#define _Thread_local
#endif

/* Some misc keywords */
#ifndef _HAS_C11
#ifdef _HAS_CXX11
#define _Noreturn [[noreturn]]
#define _Alignas(__t) alignas(__t)
#define _Alignof(__t) alignof(__t)
#elif defined(__GNUC__)
#define _Noreturn __attribute__((__noreturn__))
#define _Alignas(__t) __attribute__((__aligned__(__t)))
#define _Alignof(__t) __alignof__(__t)
#else
#error "Missing keyword support"
#endif
#endif

/* requires c11 or c++11, otherwise we fake it with a negative size array */
#if !defined(_HAS_C11)
#if defined(_HAS_CXX11)
#define _Static_assert(expr, error) static_assert((expr), error)
#else
#define _Static_assert(x, error)                                                                   \
	do {                                                                                           \
		static const char static_assertion_failed[(x) ? 1 : -1];                                   \
		(void)static_assertion_failed;                                                             \
	} while (0)
#endif
#endif

#endif
