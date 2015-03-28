
#ifndef FEATURES_20051228_H_
#define FEATURES_20051228_H_

#ifdef __STDC_VERSION__
#if __STDC_VERSION__ >= 201112L
#define __ISOC11_SOURCE
#endif

#if __STDC_VERSION__ >= 199901L
#define __ISOC99_SOURCE
#endif

#if __STDC_VERSION__ >= 199409L
#define __ISOC94_SOURCE
#endif

#define __ISOC90_SOURCE
#endif

#ifdef __cplusplus
#if __cplusplus >= 201103L
#define __ISOCXX11_SOURCE
#endif

#define __ISOCXX03_SOURCE
#define __ISOCXX89_SOURCE
#endif


#if defined(__ISOC99_SOURCE)
#define __ELIBC_RESTRICT restrict
#elif defined(__GNUC__) || defined(__clang__)
#define __ELIBC_RESTRICT __restrict
#else
#define __ELIBC_RESTRICT
#endif

#if !defined(__GNUC__) && defined(__clang__)
#define __attribute__(x)
#endif

#if defined(__ISOCXX11_SOURCE)
	#define __ELIBC_NOTHROW noexcept
#elif defined(__ISOCXX89_SOURCE)
	#define __ELIBC_NOTHROW throw()
#elif defined(__GNUC__)
	#define __ELIBC_NOTHROW __attribute__((__nothrow__))
#else
	#define __ELIBC_NOTHROW
#endif

#if defined(__GNUC__)
#define __ELIBC_CONST      __attribute__((__const__))
#define __ELIBC_PURE       __attribute__((__pure__))
#define __ELIBC_DEPRECATED __attribute__((__deprecated__))
#else
#define __ELIBC_CONST 
#define __ELIBC_PURE
#define __ELIBC_DEPRECATED
#endif

/* TODO: enable TLS */
#if !defined(__ISOC11_SOURCE) && defined(__GNUC__) && !defined(__KERNEL__)
#define _Thread_local /*__thread*/
#else
#define _Thread_local
#endif

#if defined(__ISOCXX11_SOURCE)
	#define _Noreturn   /* [[noreturn]] */ __attribute__((__noreturn__))
	#if defined(__GNUC__)
		#define _Alignas(t) __attribute__((__aligned__(t)))
		#define _Alignof(t) __alignof__(t)
	#else
		#define _Alignas(t)
		#define _Alignof(t)	
	#endif
#else
	#if !defined(__ISOC11_SOURCE)
	#if defined(__GNUC__)
	#define _Noreturn   __attribute__((__noreturn__))
	#define _Alignas(t) __attribute__((__aligned__(t)))
	#define _Alignof(t) __alignof__(t)
	#else
	#define _Noreturn
	#define _Alignas(t)
	#define _Alignof(t)
	#endif
	#endif
#endif


/* requires c11 or c++11, otherwise we fake it with a negative size array */
#if !defined(__ISOC11_SOURCE)
#if defined(__ISOCXX11_SOURCE)
	#define _Static_assert(expr, error) static_assert((expr), error)
#else
	#define _Static_assert(x, error)                             \
	do {                                                         \
		static const char static_assertion_failed[(x) ? 1 : -1]; \
		(void)static_assertion_failed;                           \
	} while(0)
#endif
#endif

#endif
