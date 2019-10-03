
#define __ELIBC_SOURCE
#include <assert.h>
#include <stdlib.h>
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: mbtowc
//----------------------------------------------------------------------------*/
int mbtowc(wchar_t *_RESTRICT pwc, const char *_RESTRICT s, size_t n) {

	static _Thread_local mbstate_t ps;
	return (int)mbrtowc(pwc, s, n, &ps);
}
