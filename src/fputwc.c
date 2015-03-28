
#define __ELIBC_SOURCE
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>
#include "c/_support.h"

/*------------------------------------------------------------------------------
// Name: fputwc
//----------------------------------------------------------------------------*/
wint_t fputwc(wchar_t wc, FILE *stream) {

	char buf[MB_LEN_MAX];
	int r = wc;
	const int n = wctomb(buf, wc);

	if(n > 0) {
		int i;
		__elibc_lock_stream(stream);
		for(i = 0; i < n; ++i) {
			if(__elibc_fputc(wc, stream, 0x03) == -1) {
				r = WEOF;
				break;
			}
		}
		__elibc_unlock_stream(stream);
	}

	return r;
}
