
#define __ELIBC_SOURCE
#include <stdlib.h>
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: wctomb
//----------------------------------------------------------------------------*/
int wctomb(char *s, wchar_t wc) {

	if(!s) {
		/* does the encoding have a non-trivial shift state?
		 * we use only UTF-8, so the answer is yes, it is in fact stateful
		 * TODO: is this dependant on the locale?
		 */
		 return 1;
	}

	return wcrtomb(s, wc, 0);
}
