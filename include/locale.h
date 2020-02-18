/* C89, C94, C99 Compliant */

#ifndef _LOCALE_H_20051228_
#define _LOCALE_H_20051228_

#include "c/c-config.h"

#include "c/_null.h"  /* NULL         */
#include "c/_lconv.h" /* struct lconv */

#define __ELIBC_ASCII 0
#define __ELIBC_UTF8  1

#define __ELIBC_LC_COLLATE  0
#define __ELIBC_LC_CTYPE    1
#define __ELIBC_LC_MONETARY 2
#define __ELIBC_LC_NUMERIC  3
#define __ELIBC_LC_TIME     4
#define __ELIBC_LC_ALL      5 /* special index for giving the primary category in results */

#define LC_COLLATE  (1 << __ELIBC_LC_COLLATE)
#define LC_CTYPE    (1 << __ELIBC_LC_CTYPE)
#define LC_MONETARY (1 << __ELIBC_LC_MONETARY)
#define LC_NUMERIC  (1 << __ELIBC_LC_NUMERIC)
#define LC_TIME     (1 << __ELIBC_LC_TIME)
#define LC_ALL      (LC_COLLATE | LC_CTYPE | LC_MONETARY | LC_NUMERIC | LC_TIME)

int __elibc_get_locale_type(int category) _NOEXCEPT;

#include "c/setlocale.h"
#include "c/localeconv.h"

#endif
