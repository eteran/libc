
#ifndef _ARCH_I686_ARCH_STDARG_H_20100128_
#define _ARCH_I686_ARCH_STDARG_H_20100128_

#if defined(__GNUC__)
#define va_start(v,l)        __builtin_va_start(v, l)
#define va_end(v)            __builtin_va_end(v)
#define va_arg(v,l)          __builtin_va_arg(v, l)
#define __elibc_va_copy(d,s) __builtin_va_copy(d, s)
#else
#error "No implementation of varargs supported"
#endif

#endif
