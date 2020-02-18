/* C89, C94, C99 Compliant */

#ifndef _CTYPE_H_20051228_
#define _CTYPE_H_20051228_

#include "c/c-config.h"

#include "c/isalnum.h"
#include "c/isalpha.h"
#include "c/iscntrl.h"
#include "c/isdigit.h"
#include "c/isgraph.h"
#include "c/islower.h"
#include "c/isprint.h"
#include "c/ispunct.h"
#include "c/isspace.h"
#include "c/isupper.h"
#include "c/isxdigit.h"
#include "c/tolower.h"
#include "c/toupper.h"

#if defined(_HAS_C99) || defined(_HAS_CXX11) || defined(__ELIBC_SOURCE)
#include "c/isblank.h"
#endif

#endif
