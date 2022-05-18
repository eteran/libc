
#define _ELIBC_SOURCE
#include <wchar.h>

/*------------------------------------------------------------------------------
// Name: wcscpy
//----------------------------------------------------------------------------*/
wchar_t *wcscpy(wchar_t *_RESTRICT dest, const wchar_t *_RESTRICT src) {
	wchar_t *dest_ptr = dest;

	while (*src != '\0') {
		*dest_ptr++ = *src++;
	}

	*dest_ptr = '\0';

	return dest;
}
