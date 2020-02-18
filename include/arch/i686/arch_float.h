
#ifndef _ARCH_I686_ARCH_FLOAT_H_20051228_
#define _ARCH_I686_ARCH_FLOAT_H_20051228_

/* #define FLT_ROUNDS <integer rvalue> */

#define FLT_EVAL_METHOD 0
#define FLT_RADIX       2
#define DECIMAL_DIG     21

#define FLT_DIG         6
#define FLT_EPSILON     1.19209289550781250000e-7F
#define FLT_MANT_DIG    24
#define FLT_MAX         3.40282346638528859812e+38F
#define FLT_MAX_10_EXP  38
#define FLT_MAX_EXP     128
#define FLT_MIN         1.17549435082228750797e-38F
#define FLT_MIN_10_EXP  (-37)
#define FLT_MIN_EXP     (-125)

#define DBL_DIG         15
#define DBL_EPSILON     ((double)2.22044604925031308085e-16L)
#define DBL_MANT_DIG    53
#define DBL_MAX         ((double)1.79769313486231570815e+308L)
#define DBL_MAX_10_EXP  308
#define DBL_MAX_EXP     1024
#define DBL_MIN         ((double)2.22507385850720138309e-308L)
#define DBL_MIN_10_EXP  (-307)
#define DBL_MIN_EXP     (-1021)

/* C99 only */
#if defined(__cplusplus) || defined(_HAS_C99) || defined(__ELIBC_SOURCE)
	#define LDBL_DIG        18
	#define LDBL_EPSILON    1.08420217248550443401e-19L
	#define LDBL_MANT_DIG   64
	#define LDBL_MAX        1.18973149535723176502e+4932L
	#define LDBL_MAX_10_EXP 4932
	#define LDBL_MAX_EXP    16384
	#define LDBL_MIN        3.36210314311209350626e-4932L
	#define LDBL_MIN_10_EXP (-4931)
	#define LDBL_MIN_EXP    (-16381)
#endif

#endif
