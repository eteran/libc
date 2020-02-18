/* C89, C94, C99 Compliant */

#ifndef _WCHAR_H_20051228_
#define _WCHAR_H_20051228_

#include "c/c-config.h"
#include "c/_c94_warning.h"

#include "arch_wchar_t.h"    /* wchar_t   */
#include "arch_size_t.h"     /* size_t    */
#include "c/_mbstate_t.h" /* mbstate_t */
#include "c/_wint_t.h"    /* wint_t    */
#include "c/_null.h"      /* NULL      */

struct tm;

/* TODO(eteran): does FILE get defined in this header? seems required ... */
#include "c/_file.h"      /* FILE      */

#ifndef WEOF
#define WEOF ((wint_t)-1)
#endif

#ifdef __WCHAR_MAX__
#define WCHAR_MAX __WCHAR_MAX__
#else
#define WCHAR_MAX 2147483647
#endif
#define WCHAR_MIN (-WCHAR_MAX - 1)

#include "c/btowc.h"
#include "c/fgetwc.h"
#include "c/fgetws.h"
#include "c/fputwc.h"
#include "c/fputws.h"
#include "c/fwide.h"
#include "c/fwprintf.h"
#include "c/fwscanf.h"
#include "c/getwc.h"
#include "c/getwchar.h"
#include "c/mbrlen.h"
#include "c/mbrtowc.h"
#include "c/mbsinit.h"
#include "c/mbsrtowcs.h"
#include "c/putwc.h"
#include "c/putwchar.h"
#include "c/swprintf.h"
#include "c/swscanf.h"
#include "c/ungetwc.h"
#include "c/vfwprintf.h"
#include "c/vswprintf.h"
#include "c/vwprintf.h"
#include "c/wcrtomb.h"
#include "c/wcscat.h"
#include "c/wcschr.h"
#include "c/wcscmp.h"
#include "c/wcscoll.h"
#include "c/wcscpy.h"
#include "c/wcscspn.h"
#include "c/wcsftime.h"
#include "c/wcslen.h"
#include "c/wcsncat.h"
#include "c/wcsncmp.h"
#include "c/wcsncpy.h"
#include "c/wcspbrk.h"
#include "c/wcsrchr.h"
#include "c/wcsrtombs.h"
#include "c/wcsspn.h"
#include "c/wcsstr.h"
#include "c/wcstod.h"
#include "c/wcstok.h"
#include "c/wcstol.h"
#include "c/wcstoul.h"
#include "c/wcsxfrm.h"
#include "c/wctob.h"
#include "c/wmemchr.h"
#include "c/wmemcmp.h"
#include "c/wmemcpy.h"
#include "c/wmemmove.h"
#include "c/wmemset.h"
#include "c/wprintf.h"
#include "c/wscanf.h"

#if defined(_HAS_C99) || defined(_HAS_CXX11) || defined(__ELIBC_SOURCE)
#include "c/vfwscanf.h"
#include "c/vswscanf.h"
#include "c/vwscanf.h" 
#include "c/wcstof.h"  
#include "c/wcstold.h" 
#include "c/wcstoll.h" 
#include "c/wcstoull.h"
#endif

#ifdef __ELIBC_SOURCE
#include "c/wcswidth.h" /* POSIX.1-2001 */
#include "c/wcwidth.h"  /* POSIX.1-2001 */

#endif

#endif
