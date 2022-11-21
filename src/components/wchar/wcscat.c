
#define _ELIBC_SOURCE
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: strcat
//----------------------------------------------------------------------------*/
wchar_t *wcscat(wchar_t *_RESTRICT dest, const wchar_t *_RESTRICT src) {
	wchar_t *dest_ptr = dest;

	/* find the end of the string... */
	while (*dest_ptr != L'\0') {
		++dest_ptr;
	}

	/* copy the new string to that location */
	while (*src != L'\0') {
		*dest_ptr++ = *src++;
	}

	*dest_ptr = L'\0';

	/* return pointer to combined string */
	return dest;
}
