
#define _ELIBC_SOURCE
#include <stdio.h>
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: ungetwc
//----------------------------------------------------------------------------*/
wint_t ungetwc(wint_t wc, FILE *stream) {
	_UNUSED(wc);
	_UNUSED(stream);

	/* TODO(eteran): implement this */
	return WEOF;
}
