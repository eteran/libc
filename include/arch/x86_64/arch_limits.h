
#ifndef _ARCH_X86_64_ARCH_LIMITS_H_20051228_
#define _ARCH_X86_64_ARCH_LIMITS_H_20051228_

#ifdef __CHAR_BIT__
#define CHAR_BIT __CHAR_BIT__
#else
#define CHAR_BIT 8
#endif

#ifndef __CHAR_UNSIGNED__
#define CHAR_MAX SCHAR_MAX
#define CHAR_MIN SCHAR_MIN
#else
#define CHAR_MAX UCHAR_MAX
#define CHAR_MIN 0
#endif

#define UCHAR_MAX 0xff
#define SCHAR_MAX 127
#define SCHAR_MIN (-128)

#define USHRT_MAX 0xffff
#define SHRT_MAX  32767
#define SHRT_MIN  (-32768)

#define UINT_MAX 0xffffffffU
#define INT_MAX  0x7fffffff
#define INT_MIN  (-INT_MAX - 1)

#define ULONG_MAX 18446744073709551615UL
#define LONG_MAX  9223372036854775807L
#define LONG_MIN  (-LONG_MAX - 1L)

/* based on the assumption that mb == utf-8. 
 * this really should be 4 since unicode is artificially restrited 
 * but it hypothetically can support 6, so ... doesn't hurt to plan
 * ahead
 */
#define MB_LEN_MAX 6

#if defined(_HAS_C99) || defined(_HAS_CXX11) || defined(__ELIBC_SOURCE)
#define LLONG_MAX  9223372036854775807LL
#define LLONG_MIN  (-LLONG_MAX - 1LL)
#define ULLONG_MAX 18446744073709551615ULL
#endif

#endif
