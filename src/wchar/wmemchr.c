
#define __ELIBC_SOURCE
#include <assert.h>
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: wmemchr
//----------------------------------------------------------------------------*/
wchar_t *wmemchr(const wchar_t *s, wchar_t c, size_t n) {

	const wchar_t *s_ptr = s;
	const wchar_t cmp    = c;

	assert(s);

	while (n--) {
		if (*s_ptr == cmp) {
			return (wchar_t *)s_ptr;
		}
		++s_ptr;
	}

	return 0;
}
