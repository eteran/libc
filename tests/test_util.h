
#ifndef _ELIBC_TEST_UTIL_H_
#define _ELIBC_TEST_UTIL_H_

#define IS_CONSTANT(n) __builtin_constant_p(n)
#define TYPE_DEFNIED(T) (void)(T*)0;
#define IS_SAME_TYPE(value, T) __builtin_types_compatible_p(__typeof__(value), T)


#endif
