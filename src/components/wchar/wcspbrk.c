
#define _ELIBC_SOURCE
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: wcspbrk
//----------------------------------------------------------------------------*/
wchar_t *wcspbrk(const wchar_t *s, const wchar_t *accept) {
	const wchar_t *ret = 0;

	while (*s != '\0') {
		if (wcschr(accept, *s) != 0) {
			ret = s;
			break;
		}
		++s;
	}

	return (wchar_t *)ret;
}
