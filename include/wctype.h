/* C89, C94, C99 Compliant */

#ifndef WCTYPE_20051228_H_
#define WCTYPE_20051228_H_

#include "c/c-config.h"
#include "c/_c94_warning.h"

#include "c/_wint_t.h"    /* wint_t    */
#include "c/_wctrans_t.h" /* wctrans_t */
#include "c/_wctype_t.h"  /* wctype_t  */

#ifndef WEOF
#define WEOF ((wint_t)-1)
#endif

#include "c/iswalnum.h"
#include "c/iswalpha.h"
#include "c/iswcntrl.h"
#include "c/iswdigit.h"
#include "c/iswgraph.h"
#include "c/iswlower.h"
#include "c/iswprint.h"
#include "c/iswpunct.h"
#include "c/iswspace.h"
#include "c/iswupper.h"
#include "c/iswxdigit.h"
#include "c/iswctype.h"
#include "c/wctype.h"
#include "c/towlower.h"
#include "c/towupper.h"
#include "c/towctrans.h"
#include "c/wctrans.h"

#if defined(__ISOC99_SOURCE) || defined(__ISOCXX11_SOURCE) || defined(__ELIBC_SOURCE)
#include "c/iswblank.h"
#endif

#endif
