
#define __ELIBC_SOURCE
#include <assert.h>
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: wmemset
//----------------------------------------------------------------------------*/
wchar_t *wmemset(wchar_t *s, wchar_t c, size_t n) {

	/* traditional memset */
	wchar_t *s_ptr   = s;
	const wchar_t ch = c;

	assert(s);

	while (n--) {
		*s_ptr++ = ch;
	}

	return s;
}
