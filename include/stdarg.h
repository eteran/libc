/* C89, C94, C99 Compliant */

#ifndef _STDARG_H_20051228_
#define _STDARG_H_20051228_

#include "c/c-config.h"

#include "arch_va_list.h" /* va_list */
#include "arch_stdarg.h"  /* va_arg, va_end, va_start */

#if defined(_HAS_C99) || defined(_HAS_CXX11) || defined(__ELIBC_SOURCE)
#define va_copy __elibc_va_copy
#endif

#endif

