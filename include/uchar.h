/* C89, C94, C99 Compliant */

#ifndef _UCHAR_H_20130922_
#define _UCHAR_H_20130922_

#include "c/c-config.h"

#include "c/_c11_warning.h"

#include "arch_size_t.h"
#include "c/_mbstate_t.h"

#if !defined(__cpp_unicode_characters)

#ifdef __CHAR16_TYPE__
typedef __CHAR16_TYPE__ char16_t;
#endif

#ifdef __CHAR32_TYPE__
typedef __CHAR32_TYPE__ char32_t;
#endif

#endif

#ifndef __STDC_UTF_16__
#define __STDC_UTF_16__
#endif

#ifndef __STDC_UTF_32__
#define __STDC_UTF_32__
#endif

size_t c16rtomb(char *s, char16_t c16, mbstate_t *ps);
size_t c32rtomb(char *s, char32_t c32, mbstate_t *ps);
size_t mbrtoc16(char16_t *pc16, const char *s, size_t n, mbstate_t *ps);
size_t mbrtoc32(char32_t *pc32, const char *s, size_t n, mbstate_t *ps);

#endif
