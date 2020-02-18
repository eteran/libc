
#ifndef _ARCH_I686_ARCH_STDINT_H_20051228_
#define _ARCH_I686_ARCH_STDINT_H_20051228_

typedef signed char            int8_t;
typedef signed short int       int16_t;
typedef signed long int        int32_t;
typedef signed long long int   int64_t;

typedef unsigned char          uint8_t;
typedef unsigned short int     uint16_t;
typedef unsigned long int      uint32_t;
typedef unsigned long long int uint64_t;

typedef int8_t                 int_least8_t;
typedef int16_t                int_least16_t;
typedef int32_t                int_least32_t;
typedef int64_t                int_least64_t;

typedef uint8_t                uint_least8_t;
typedef uint16_t               uint_least16_t;
typedef uint32_t               uint_least32_t;
typedef uint64_t               uint_least64_t;

typedef int8_t                 int_fast8_t;
typedef int16_t                int_fast16_t;
typedef int32_t                int_fast32_t;
typedef int64_t                int_fast64_t;

typedef uint8_t                uint_fast8_t;
typedef uint16_t               uint_fast16_t;
typedef uint32_t               uint_fast32_t;
typedef uint64_t               uint_fast64_t;

typedef int32_t                intptr_t;
typedef uint32_t               uintptr_t;

typedef int64_t                intmax_t;
typedef uint64_t               uintmax_t;

#if defined(__STDC_LIMIT_MACROS)

#define INT8_MAX  127
#define INT16_MAX 32767
#define INT32_MAX 2147483647
#define INT64_MAX 9223372036854775807

#define INT8_MIN  (-127)
#define INT16_MIN (-32767)
#define INT32_MIN (-2147483647)
#define INT64_MIN (-9223372036854775807LL)

#define UINT8_MAX  0xff
#define UINT16_MAX 0xffff
#define UINT32_MAX 0xffffffff
#define UINT64_MAX 0xffffffffffffffffULL

#define INTMAX_MIN      INT64_MIN
#define INTMAX_MAX      INT64_MAX
#define UINTMAX_MAX     UINT64_MAX

#define INT_LEAST8_MIN  INT8_MIN
#define INT_LEAST16_MIN INT16_MIN
#define INT_LEAST32_MIN INT32_MIN
#define INT_LEAST64_MIN INT64_MIN

#define INT_LEAST8_MAX  INT8_MAX
#define INT_LEAST16_MAX INT16_MAX
#define INT_LEAST32_MAX INT32_MAX
#define INT_LEAST64_MAX INT64_MAX

#define INT_FAST8_MIN   INT8_MIN
#define INT_FAST16_MIN  INT16_MIN
#define INT_FAST32_MIN  INT32_MIN
#define INT_FAST64_MIN  INT64_MIN

#define INT_FAST8_MAX   INT8_MAX
#define INT_FAST16_MAX  INT16_MAX
#define INT_FAST32_MAX  INT32_MAX
#define INT_FAST64_MAX  INT64_MAX

#define UINT_FAST8_MAX  UINT8_MAX
#define UINT_FAST16_MAX UINT16_MAX
#define UINT_FAST32_MAX UINT32_MAX
#define UINT_FAST64_MAX UINT64_MAX

#define INTPTR_MIN      INT32_MIN
#define INTPTR_MAX      INT32_MAX
#define UINTPTR_MAX     UINT32_MAX

#define PTRDIFF_MIN     INT32_MIN
#define PTRDIFF_MAX     INT32_MAX

#define SIG_ATOMIC_MIN
#define SIG_ATOMIC_MAX

#define SIZE_MAX UINT32_MAX

#ifdef __WCHAR_MAX__
#define WCHAR_MAX __WCHAR_MAX__
#else
#define WCHAR_MAX 2147483647
#endif
#define WCHAR_MIN (-WCHAR_MAX - 1)


#define WINT_MIN
#define WINT_MAX

#endif

#if defined(__STDC_CONSTANT_MACROS)

#define INT8_C(value)    value
#define INT16_C(value)   value
#define INT32_C(value)   value ## L
#define INT64_C(value)   value ## LL

#define UINT8_C(value)   value ## U
#define UINT16_C(value)  value ## U
#define UINT32_C(value)  value ## UL
#define UINT64_C(value)  value ## ULL

#define INTMAX_C(value)  value ## LL
#define UINTMAX_C(value) value ## ULL

#endif
 
#endif
