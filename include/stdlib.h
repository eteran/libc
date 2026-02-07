/* C89, C94, C99 Compliant */

#ifndef _STDLIB_H_20051228_
#define _STDLIB_H_20051228_

#include "c/c-config.h"

#define EXIT_FAILURE (-1)
#define EXIT_SUCCESS 0

/* C99+ is needed to support VLAs */
#ifdef _HAS_C99
#define MB_CUR_MAX __ctype_get_mb_cur_max()
#else
#define MB_CUR_MAX ((size_t)4)
#endif


#include "arch_size_t.h"
#include "arch_stdlib.h"
#include "arch_wchar_t.h"
#include "c/_null.h"

#include "c/abort.h"
#include "c/abs.h"
#include "c/atexit.h"
#include "c/atof.h"
#include "c/atoi.h"
#include "c/atol.h"
#include "c/bsearch.h"
#include "c/calloc.h"
#include "c/div.h"
#include "c/exit.h"
#include "c/free.h"
#include "c/getenv.h"
#include "c/labs.h"
#include "c/ldiv.h"
#include "c/malloc.h"
#include "c/mblen.h"
#include "c/mbstowcs.h"
#include "c/mbtowc.h"
#include "c/qsort.h"
#include "c/rand.h"
#include "c/realloc.h"
#include "c/srand.h"
#include "c/strtod.h"
#include "c/strtol.h"
#include "c/strtoul.h"
#include "c/system.h"
#include "c/wcstombs.h"

#if defined(_HAS_C99) || defined(_HAS_CXX11) || defined(_ELIBC_SOURCE)
#include "c/_Exit.h"
#include "c/atoll.h"
#include "c/llabs.h"
#include "c/lldiv.h"
#include "c/strtof.h"
#include "c/strtold.h"
#include "c/strtoll.h"
#include "c/strtoull.h"
#endif

#if defined(_HAS_C99) || defined(_HAS_CXX89) || defined(_ELIBC_SOURCE)
#include "c/wctomb.h"
#endif

extern _CONST size_t __ctype_get_mb_cur_max(void) _NOEXCEPT;

#endif
