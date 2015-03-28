/* C89, C94, C99 Compliant */

#ifndef STDDEF_20051228_H_
#define STDDEF_20051228_H_

#include "c/c-config.h"

#include "arch_ptrdiff_t.h" /* ptrdiff_t */
#include "arch_size_t.h"    /* size_t    */
#include "arch_wchar_t.h"   /* wchar_t   */
#include "c/_null.h"     /* NULL      */
#include "c/offsetof.h"  /* offsetof  */

#if defined(__ISOC11_SOURCE) || defined(__ELIBC_SOURCE)
#include "arch_max_align_t.h"
#endif

#endif
