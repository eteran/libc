/* C89, C94, C99 Compliant */

#ifndef STDLIB_20051228_H_
#define STDLIB_20051228_H_

#include "c/c-config.h"

#define EXIT_FAILURE (-1)
#define EXIT_SUCCESS 0

#define MB_CUR_MAX __ctype_get_mb_cur_max()

#include "arch_size_t.h"  /* size_t   */
#include "arch_wchar_t.h" /* wchar_t  */
#include "c/_null.h"   /* NULL     */
#include "arch_stdlib.h"  /* RAND_MAX */

#include "c/atof.h"
#include "c/atoi.h"
#include "c/atol.h"
#include "c/strtod.h"
#include "c/strtol.h"
#include "c/strtoul.h"
#include "c/rand.h"
#include "c/srand.h"
#include "c/calloc.h"
#include "c/free.h"
#include "c/malloc.h"
#include "c/realloc.h"
#include "c/abort.h"
#include "c/atexit.h"
#include "c/exit.h"
#include "c/getenv.h"
#include "c/system.h"
#include "c/bsearch.h"
#include "c/qsort.h"
#include "c/abs.h"
#include "c/labs.h"
#include "c/div.h"
#include "c/ldiv.h"
#include "c/mblen.h"
#include "c/mbtowc.h"
#include "c/mbstowcs.h"
#include "c/wcstombs.h"

#if defined(__ISOC99_SOURCE) || defined(__ISOCXX11_SOURCE) || defined(__ELIBC_SOURCE)
#include "c/atoll.h"
#include "c/strtof.h"
#include "c/strtold.h"
#include "c/strtoll.h"
#include "c/strtoull.h"
#include "c/_Exit.h"
#include "c/llabs.h"
#include "c/lldiv.h"
#endif

#if defined(__ISOC99_SOURCE) || defined(__ISOCXX89_SOURCE) || defined(__ELIBC_SOURCE)
#include "c/wctomb.h"
#endif

extern __ELIBC_CONST size_t __ctype_get_mb_cur_max(void) __ELIBC_NOTHROW;

#endif
