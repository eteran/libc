
#define _ELIBC_SOURCE
#include "c/_support.h"
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>

/*------------------------------------------------------------------------------
// Name: __elibc_fputwc_unlocked
//----------------------------------------------------------------------------*/
wint_t __elibc_fputwc_unlocked(wchar_t wc, FILE *stream) {
	char buf[MB_LEN_MAX];
	wint_t r    = (wint_t)wc;
	const int n = wctomb(buf, wc);

	if (n > 0) {
		int i;
		for (i = 0; i < n; ++i) {
			if (__elibc_fputc(wc, stream, _ELIBC_FILE_WIDE) == EOF) {
				r = WEOF;
				break;
			}
		}
	}

	return r;
}

/*------------------------------------------------------------------------------
// Name: fputwc
//----------------------------------------------------------------------------*/
wint_t fputwc(wchar_t wc, FILE *stream) {
	wint_t r;
	__ELIBC_WITH_LOCK(__elibc_fputwc_unlocked(wc, stream), &r);
	return r;
}
