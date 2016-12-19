
#define __ELIBC_SOURCE
#include <stdlib.h>
#include <wchar.h>
#include <assert.h>

/*------------------------------------------------------------------------------
// Name: mbtowc
//----------------------------------------------------------------------------*/
int mbtowc(wchar_t *__ELIBC_RESTRICT pwc, const char *__ELIBC_RESTRICT s, size_t n) {

	_Thread_local static mbstate_t ps;
	return (int)mbrtowc(pwc, s, n, &ps);
}
