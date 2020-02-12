
#define __ELIBC_SOURCE
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: wcsrchr
//----------------------------------------------------------------------------*/
wchar_t *wcsrchr(const wchar_t *s, wchar_t c) {
	const wchar_t *ret = 0;
	const wchar_t cmp  = c;

	while (*s != '\0') {
		if (*s == cmp) {
			ret = s;
		}
		++s;
	}

	return (wchar_t *)ret;
}
