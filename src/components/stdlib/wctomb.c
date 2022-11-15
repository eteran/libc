
#define _ELIBC_SOURCE
#include <stdlib.h>
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: wctomb
//----------------------------------------------------------------------------*/
int wctomb(char *s, wchar_t wc) {

	if (!s) {
		/* does the encoding have a non-trivial shift state?
		 * in UTF-8, conversion from wchar_t to mb can be done all at once since
		 * s is guaranteed to have enough space by the standard
		 */
		return 0;
	}

	return (int)wcrtomb(s, wc, 0);
}
