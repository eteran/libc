
#ifndef _ELIBC_TEST_UTIL_H_
#define _ELIBC_TEST_UTIL_H_

#define IS_CONSTANT(n)         __builtin_constant_p(n)
#define IS_SAME_TYPE(value, T) __builtin_types_compatible_p(__typeof__(value), T)

#define TYPE_DEFINED(T)                                                                            \
	do {                                                                                           \
		(void)(T *)0;                                                                              \
	} while (0)

#endif
