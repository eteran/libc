/* C89, C94, C99 Compliant */

#ifndef STDARG_20051228_H_
#define STDARG_20051228_H_

#include "c/c-config.h"

#include "arch_va_list.h" /* va_list */
#include "arch_stdarg.h"  /* va_arg, va_end, va_start */

#if defined(__ISOC99_SOURCE) || defined(__ISOCXX11_SOURCE) || defined(__ELIBC_SOURCE)
#define va_copy __elibc_va_copy
#endif

#endif

