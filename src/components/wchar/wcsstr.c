
#define _ELIBC_SOURCE
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: wcsnstr
//----------------------------------------------------------------------------*/
wchar_t *wcsnstr(const wchar_t *haystack, const wchar_t *needle, size_t n) {

	if (needle[0] == '\0') {
		return (wchar_t *)haystack;
	} else {
		while (*haystack != '\0') {
			if (wcsncmp(haystack, needle, n) == 0) {
				return (wchar_t *)haystack;
			}
			++haystack;
		}
	}

	return 0;
}

/*------------------------------------------------------------------------------
// Name: wcsstr
//----------------------------------------------------------------------------*/
wchar_t *wcsstr(const wchar_t *haystack, const wchar_t *needle) {
	return wcsnstr(haystack, needle, wcslen(needle));
}
