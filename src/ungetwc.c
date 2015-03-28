
#define __ELIBC_SOURCE
#include <wchar.h>
#include <stdio.h>

/*------------------------------------------------------------------------------
// Name: ungetwc
//----------------------------------------------------------------------------*/
wint_t ungetwc(wint_t wc, FILE *stream) {
	(void)wc;
	(void)stream;
	return WEOF;
}
