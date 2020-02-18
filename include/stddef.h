/* C89, C94, C99 Compliant */

#ifndef _STDDEF_H_20051228_
#define _STDDEF_H_20051228_

#include "c/c-config.h"

#include "arch_ptrdiff_t.h" /* ptrdiff_t */
#include "arch_size_t.h"    /* size_t    */
#include "arch_wchar_t.h"   /* wchar_t   */
#include "c/_null.h"        /* NULL      */
#include "c/offsetof.h"     /* offsetof  */

#if defined(_HAS_C11) || defined(__ELIBC_SOURCE)
#include "arch_max_align_t.h"
#endif

#endif
