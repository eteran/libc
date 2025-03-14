/* C89, C94, C99 Compliant */

#ifndef _STRING_H_20051228_
#define _STRING_H_20051228_

#include "c/c-config.h"

#include "arch_size_t.h"
#include "c/_null.h"

/* prototypes for all functions */
#include "c/memchr.h"
#include "c/memcmp.h"
#include "c/memcpy.h"
#include "c/memmove.h"
#include "c/memset.h"
#include "c/strcat.h"
#include "c/strchr.h"
#include "c/strcmp.h"
#include "c/strcoll.h"
#include "c/strcpy.h"
#include "c/strcspn.h"
#include "c/strerror.h"
#include "c/strlen.h"
#include "c/strncat.h"
#include "c/strncmp.h"
#include "c/strncpy.h"
#include "c/strpbrk.h"
#include "c/strrchr.h"
#include "c/strspn.h"
#include "c/strstr.h"
#include "c/strtok.h"
#include "c/strxfrm.h"

/* some extensions to the string library */
#ifdef _ELIBC_SAFE_STRING
#include "c/strdup.h"
#include "c/strlcat.h"
#include "c/strlcpy.h"
#include "c/strndup.h"
#endif

/* some extensions that are just useful */
#ifdef _ELIBC_STRING_UTIL
#include "c/memswp.h"
#endif

#endif
