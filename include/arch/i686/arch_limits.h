
#ifndef _ARCH_I686_ARCH_LIMITS_H_20051228_
#define _ARCH_I686_ARCH_LIMITS_H_20051228_

#ifdef __CHAR_BIT__
#define CHAR_BIT __CHAR_BIT__
#else
#define CHAR_BIT 8
#endif

#define SCHAR_MAX 127
#define SCHAR_MIN (-128)
#define UCHAR_MAX 0xff

#define SHRT_MAX  32767
#define SHRT_MIN  (-32768)
#define USHRT_MAX 0xffff

#define INT_MAX  0x7fffffff
#define INT_MIN  (-INT_MAX - 1)
#define UINT_MAX 4294967295U

#define LONG_MAX  2147483647L
#define LONG_MIN  (-LONG_MAX - 1L)
#define ULONG_MAX 4294967295UL

/* C99 only */
#define LLONG_MAX   9223372036854775807LL
#define LLONG_MIN  (-LLONG_MAX - 1LL)
#define ULLONG_MAX 18446744073709551615ULL

#ifndef __CHAR_UNSIGNED__
#define CHAR_MAX SCHAR_MAX
#define CHAR_MIN SCHAR_MIN
#else
#define CHAR_MAX UCHAR_MAX
#define CHAR_MIN 0
#endif

/* based on the assumption that mb == utf-8 */
#define MB_LEN_MAX 4

#endif
