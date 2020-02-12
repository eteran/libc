
#define __ELIBC_SOURCE
#include <stdio.h>
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: ungetwc
//----------------------------------------------------------------------------*/
wint_t ungetwc(wint_t wc, FILE *stream) {
	(void)wc;
	(void)stream;
	return WEOF;
}
