
#define __ELIBC_SOURCE
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: wcschr
//----------------------------------------------------------------------------*/
wchar_t *wcschr(const wchar_t *s, wchar_t c) {
	const wchar_t cmp = c;

	while(*s != '\0') {
		if(*s == cmp) {
			return (wchar_t *)s;
		}
		++s;
	}

	return 0;
}
